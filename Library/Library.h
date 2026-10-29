#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <string>
#include <fstream>   // 实验六：文件流头文件
#include "Book.h"

class Library {
private:
    std::vector<Book*> resourceList;
public:
    ~Library();

    void addResource(Book* res);
    bool addResourceCount(const std::string& isbn, int num);
    Book* findResource(const std::string& isbn);
    void showResource(const std::string& isbn);
    void showAllResources();
    bool reduceResourceCount(const std::string& isbn, int num);
    bool deleteResource(const std::string& isbn);

    // ==========文件持久化函数 ==========
    void saveToFile(const std::string& filename);   // 保存所有资源到文件
    void loadFromFile(const std::string& filename); // 从文件加载所有资源
};

#endif