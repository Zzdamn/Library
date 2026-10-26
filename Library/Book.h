#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

// 抽象基类：Book
class Book {
protected:
    std::string bookName;
    std::string isbn;
    std::string publisher;
    double price;
    int totalCount;
    int availableCount;
    void printBaseInfo() const;

public:
    Book();
    virtual ~Book();

    // 原有函数全部保留，接口不变
    void initData(const std::string& n, const std::string& id, const std::string& pub, double p, int total);
    std::string getIsbn() const;
    std::string getBookName() const;
    bool getStatus() const;
    void addCount(int num);
    bool reduceCount(int num);
    bool borrowOne();
    virtual void returnOne(); // 修改点：改为虚函数，子类重写实现差异化归还

    bool verifyIsbn() const;

    // 纯虚函数，多态核心
    virtual void print() const = 0;
    virtual std::string getType() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Book& book);
};

// 派生类1：普通图书
class GeneralBook : public Book {
private:
    int pageNum;
public:
    GeneralBook();
    void initGeneralBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, int pg);
    void print() const override;
    std::string getType() const override;
    void returnOne() override; // 新增：重写归还逻辑
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
    void returnOne() override; // 新增：重写归还逻辑
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
    void returnOne() override; // 新增：重写归还逻辑
};

#endif