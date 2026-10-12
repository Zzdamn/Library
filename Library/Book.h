#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

// 基类：Book（保留原类名，所有原有公共变量、函数名均保留）
class Book {
protected:
    std::string bookName;    // 资源名称，原有变量名保留
    std::string isbn;        // 资源编号，原有变量名保留
    std::string publisher;   // 出版社/出品方，原有变量名保留
    double price;            // 价格，原有变量名保留
    int totalCount;          // 新增：总馆藏数量
    int availableCount;      // 新增：当前可借数量

public:
    Book();
    virtual ~Book(); // 虚析构函数，派生类指针释放时防止内存泄漏

    // 原有函数名全部保留
    void initData(const std::string& n, const std::string& id, const std::string& pub, double p, int total);
    std::string getIsbn();
    std::string getBookName();
    bool getStatus(); // 原有接口保留，内部改为判断可借数量>0
    void addCount(int num);  // 增加馆藏数量
    bool reduceCount(int num); // 减少馆藏数量
    bool borrowOne();  // 借出1本
    void returnOne();  // 归还1本

    virtual void print(); // 虚函数，子类重写，体现多态
    bool verifyIsbn();
};

// 派生类1：普通图书
class GeneralBook : public Book {
private:
    int pageNum; // 原有变量，挪至子类，普通图书特有
public:
    GeneralBook();
    void initGeneralBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, int pg);
    void print() override; // 重写基类虚函数
};

// 派生类2：杂志
class Magazine : public Book {
private:
    std::string issue; // 期号，杂志特有
public:
    Magazine();
    void initMagazine(const std::string& n, const std::string& id, const std::string& pub, double p, int total, const std::string& iss);
    void print() override;
};

// 派生类3：电子资源
class EBook : public Book {
private:
    double fileSize; // 文件大小，电子资源特有
    std::string format; // 文件格式，电子资源特有
public:
    EBook();
    void initEBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, double fs, const std::string& fmt);
    void print() override;
};

#endif