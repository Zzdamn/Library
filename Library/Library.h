#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include <string>
#include "Book.h"

class Library {
private:
    std::vector<Book*> resourceList; // STL容器，存储基类指针，支持多态
public:
    ~Library(); // 析构释放所有new的对象

    void addResource(Book* res);       // 1. 增加新资源
    bool addResourceCount(const std::string& isbn, int num); // 2. 增加已有资源数量
    Book* findResource(const std::string& isbn); // 查找资源
    void showResource(const std::string& isbn); // 3. 显示单个资源
    void showAllResources();           // 4. 显示所有资源
    bool reduceResourceCount(const std::string& isbn, int num); // 5. 减少资源数量
    bool deleteResource(const std::string& isbn); // 6. 删除资源
};

#endif