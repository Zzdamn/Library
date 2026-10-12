#pragma execution_character_set("utf-8")
#include "Book.h"

// ========== 基类Book实现 ==========
Book::Book() : totalCount(0), availableCount(0) {}

Book::~Book() {}

void Book::initData(const std::string& n, const std::string& id, const std::string& pub, double p, int total)
{
    bookName = n;
    isbn = id;
    publisher = pub;
    price = p;
    totalCount = total;
    availableCount = total;
}

std::string Book::getIsbn() { return isbn; }
std::string Book::getBookName() { return bookName; }

// 原有接口保留，兼容Student类原有调用
bool Book::getStatus() {
    return availableCount > 0;
}

void Book::addCount(int num) {
    totalCount += num;
    availableCount += num;
}

bool Book::reduceCount(int num) {
    if (num > availableCount) return false;
    totalCount -= num;
    availableCount -= num;
    return true;
}

bool Book::borrowOne() {
    if (availableCount <= 0) return false;
    availableCount--;
    return true;
}

void Book::returnOne() {
    if (availableCount < totalCount)
        availableCount++;
}

void Book::print() {
    std::cout << "Title: " << bookName << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Price: " << price << " CNY" << std::endl;
    std::cout << "Total copies: " << totalCount << ", Available: " << availableCount << std::endl;
}

bool Book::verifyIsbn() {
    return !isbn.empty();
}

// ========== 派生类GeneralBook实现 ==========
GeneralBook::GeneralBook() : pageNum(0) {}

void GeneralBook::initGeneralBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, int pg)
{
    initData(n, id, pub, p, total); // 调用基类初始化公共属性
    pageNum = pg;
}

void GeneralBook::print() {
    std::cout << "===== General Book =====" << std::endl;
    Book::print(); // 调用基类打印公共信息
    std::cout << "Pages: " << pageNum << " pages" << std::endl;
}

// ========== 派生类Magazine实现 ==========
Magazine::Magazine() {}

void Magazine::initMagazine(const std::string& n, const std::string& id, const std::string& pub, double p, int total, const std::string& iss)
{
    initData(n, id, pub, p, total);
    issue = iss;
}

void Magazine::print() {
    std::cout << "===== Magazine =====" << std::endl;
    Book::print();
    std::cout << "Issue: " << issue << std::endl;
}

// ========== 派生类EBook实现 ==========
EBook::EBook() : fileSize(0) {}

void EBook::initEBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, double fs, const std::string& fmt)
{
    initData(n, id, pub, p, total);
    fileSize = fs;
    format = fmt;
}

void EBook::print() {
    std::cout << "===== E-Book =====" << std::endl;
    Book::print();
    std::cout << "File size: " << fileSize << " MB" << std::endl;
    std::cout << "Format: " << format << std::endl;
}