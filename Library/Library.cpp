#include "Library.h"
#include <iostream>
#include <sstream>
#include <filesystem>

Library::~Library() {
    for (auto res : resourceList) {
        delete res;
    }
    resourceList.clear();
}

void Library::addResource(Book* res) {
    resourceList.push_back(res);
    std::cout << "Resource added successfully." << std::endl;
}

Book* Library::findResource(const std::string& isbn) {
    for (auto res : resourceList) {
        if (res->getIsbn() == isbn) {
            return res;
        }
    }
    return nullptr;
}

bool Library::addResourceCount(const std::string& isbn, int num) {
    Book* res = findResource(isbn);
    if (!res) {
        std::cout << "Resource not found!" << std::endl;
        return false;
    }
    res->addCount(num);
    std::cout << "Count increased successfully; available count updated." << std::endl;
    return true;
}

void Library::showResource(const std::string& isbn) {
    Book* res = findResource(isbn);
    if (!res) {
        std::cout << "Resource not found!" << std::endl;
        return;
    }
    res->print();
}

void Library::showAllResources() {
    std::cout << "\n===== All Resources =====" << std::endl;
    for (auto res : resourceList) {
        res->print();
        std::cout << "-------------------------" << std::endl;
    }
}

bool Library::reduceResourceCount(const std::string& isbn, int num) {
    Book* res = findResource(isbn);
    if (!res) {
        std::cout << "Resource not found!" << std::endl;
        return false;
    }
    if (res->reduceCount(num)) {
        std::cout << "Count decreased successfully." << std::endl;
        return true;
    }
    else {
        std::cout << "Decrease failed: insufficient available count." << std::endl;
        return false;
    }
}

bool Library::deleteResource(const std::string& isbn) {
    for (auto it = resourceList.begin(); it != resourceList.end(); ++it) {
        if ((*it)->getIsbn() == isbn) {
            delete* it;
            resourceList.erase(it);
            std::cout << "Resource deleted successfully." << std::endl;
            return true;
        }
    }
    std::cout << "Resource not found, delete failed." << std::endl;
    return false;
}

// 保存数据到文件
void Library::saveToFile(const std::string& filename) {
    std::cout << "Saving data to: " << std::filesystem::absolute(filename) << std::endl;
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cout << "Save failed: cannot open file." << std::endl;
        return;
    }

    for (auto res : resourceList) {
        std::string type = res->getType();
        int typeId = 0;
        if (type == "General Book") typeId = 1;
        else if (type == "Magazine") typeId = 2;
        else if (type == "E-Book") typeId = 3;

        outFile << typeId << " "
            << res->getIsbn() << " "
            << res->getBookName() << " "
            << res->getPublisher() << " "
            << res->getPrice() << " "
            << res->getTotalCount() << " "
            << res->getAvailableCount() << " ";

        if (typeId == 1) {
            GeneralBook* gb = dynamic_cast<GeneralBook*>(res);
            if (gb) outFile << gb->getPageNum() << std::endl;
        }
        else if (typeId == 2) {
            Magazine* mg = dynamic_cast<Magazine*>(res);
            if (mg) outFile << mg->getIssue() << std::endl;
        }
        else if (typeId == 3) {
            EBook* eb = dynamic_cast<EBook*>(res);
            if (eb) outFile << eb->getFileSize() << " " << eb->getFormat() << std::endl;
        }
    }

    outFile.close();
    std::cout << "Data saved to file successfully." << std::endl;
}

// 从文件加载数据
void Library::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cout << "Load notice: data file not found, use default data." << std::endl;
        return;
    }

    for (auto res : resourceList) {
        delete res;
    }
    resourceList.clear();

    int typeId;
    std::string isbn, name, pub;
    double price;
    int total, available;

    while (inFile >> typeId >> isbn >> name >> pub >> price >> total >> available) {
        if (typeId == 1) {
            int page;
            inFile >> page;
            GeneralBook* gb = new GeneralBook();
            gb->initGeneralBook(name, isbn, pub, price, total, page);
            for (int i = 0; i < total - available; i++) gb->borrowOne();
            resourceList.push_back(gb);
        }
        else if (typeId == 2) {
            std::string issue;
            inFile >> issue;
            Magazine* mg = new Magazine();
            mg->initMagazine(name, isbn, pub, price, total, issue);
            for (int i = 0; i < total - available; i++) mg->borrowOne();
            resourceList.push_back(mg);
        }
        else if (typeId == 3) {
            double fs;
            std::string fmt;
            inFile >> fs >> fmt;
            EBook* eb = new EBook();
            eb->initEBook(name, isbn, pub, price, total, fs, fmt);
            for (int i = 0; i < total - available; i++) eb->borrowOne();
            resourceList.push_back(eb);
        }
    }

    inFile.close();
    std::cout << "Data loaded from file successfully." << std::endl;
}