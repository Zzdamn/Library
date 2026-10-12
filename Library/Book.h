#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

// 抽象基类：Book（类名、所有原有成员变量/函数名100%保留）
class Book {
protected:
    std::string bookName;    // 原有变量保留
    std::string isbn;
    std::string publisher;
    double price;
    int totalCount;
    int availableCount;

    // 新增：封装公共信息打印，供子类复用
    void printBaseInfo() const;

public:
    Book();
    virtual ~Book(); // 虚析构函数，实验四核心：delete基类指针时完整释放子类对象

    // 原有普通函数全部保留，接口不变
    void initData(const std::string& n, const std::string& id, const std::string& pub, double p, int total);
    std::string getIsbn() const;
    std::string getBookName() const;
    bool getStatus() const;
    void addCount(int num);
    bool reduceCount(int num);
    bool borrowOne();
    void returnOne();
    bool verifyIsbn() const;

    // ===== 实验四 虚函数多态核心 =====
    virtual void print() const = 0;       // 纯虚函数，Book成为抽象类，子类必须重写
    virtual std::string getType() const = 0; // 纯虚函数：返回资源类型，统一接口

    // 实验四 运算符重载多态（友元声明）
    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// 派生类1：普通图书（类名、原有变量完全保留）
class GeneralBook : public Book {
private:
    int pageNum;
public:
    GeneralBook();
    void initGeneralBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, int pg);
    void print() const override;
    std::string getType() const override;
};

// 派生类2：杂志
class Magazine : public Book {
private:
    std::string issue;
public:
    Magazine();
    void initMagazine(const std::string& n, const std::string& id, const std::string& pub, double p, int total, const std::string& iss);
    void print() const override;
    std::string getType() const override;
};

// 派生类3：电子资源
class EBook : public Book {
private:
    double fileSize;
    std::string format;
public:
    EBook();
    void initEBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, double fs, const std::string& fmt);
    void print() const override;
    std::string getType() const override;
};

#endif