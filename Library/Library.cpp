#include "Library.h"
#include <iostream>

Library::~Library() {
    // 释放所有动态创建的对象
    for (auto res : resourceList) {
        delete res;
    }
    resourceList.clear();
}

void Library::addResource(Book* res) {
    resourceList.push_back(res);
    std::cout << "Resource added successfully." << std::endl;//资源添加成功
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
        std::cout << "Resource not found!" << std::endl;//未找到该资源！
        return false;
    }
    res->addCount(num);
    std::cout << "Count increased successfully; available count updated." << std::endl;//数量增加成功，可借数已更新。
    return true;
}

void Library::showResource(const std::string& isbn) {
    Book* res = findResource(isbn);
    if (!res) {
        std::cout << "Resource not found!" << std::endl;
        return;
    }
    res->print(); // 多态调用，根据实际类型调用对应print
}

void Library::showAllResources() {
    std::cout << "\n===== All Resources =====" << std::endl;//全部馆藏资源
    for (auto res : resourceList) {
        res->print(); // 多态调用
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
        std::cout << "Count decreased successfully." << std::endl;//数量减少成功
        return true;
    }
    else {
        std::cout << "Decrease failed: insufficient available count." << std::endl;//减少失败：可借数不足
        return false;
    }
}

bool Library::deleteResource(const std::string& isbn) {
    for (auto it = resourceList.begin(); it != resourceList.end(); ++it) {
        if ((*it)->getIsbn() == isbn) {
            delete* it;
            resourceList.erase(it);
            std::cout << "Resource deleted successfully." << std::endl;//资源删除成功
            return true;
        }
    }
    std::cout << "Resource not found, delete failed." << std::endl;//未找到该资源，删除失败
    return false;
}