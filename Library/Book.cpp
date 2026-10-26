#include "Book.h"
#include <iostream>

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

std::string Book::getIsbn() const { return isbn; }
std::string Book::getBookName() const { return bookName; }
bool Book::getStatus() const { return availableCount > 0; }

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

// 基类默认归还逻辑
void Book::returnOne() {
    if (availableCount < totalCount)
        availableCount++;
}

bool Book::verifyIsbn() const {
    return !isbn.empty();
}

void Book::printBaseInfo() const {
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Title: " << bookName << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Publisher: " << publisher << std::endl;
    std::cout << "Price: " << price << " CNY" << std::endl;
    std::cout << "Total copies: " << totalCount << ", Available: " << availableCount << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Book& book)
{
    book.print();
    return os;
}

// ========== 派生类GeneralBook ==========
GeneralBook::GeneralBook() : pageNum(0) {}

void GeneralBook::initGeneralBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, int pg)
{
    initData(n, id, pub, p, total);
    pageNum = pg;
}

std::string GeneralBook::getType() const {
    return "General Book";
}

void GeneralBook::print() const {
    std::cout << "===== General Book =====" << std::endl;
    printBaseInfo();
    std::cout << "Pages: " << pageNum << std::endl;
}

// 普通图书归还
void GeneralBook::returnOne() {
    Book::returnOne();
    std::cout << "  >> Physical book: condition checked, shelved to corresponding area." << std::endl;
}

// ========== 派生类Magazine ==========
Magazine::Magazine() {}

void Magazine::initMagazine(const std::string& n, const std::string& id, const std::string& pub, double p, int total, const std::string& iss)
{
    initData(n, id, pub, p, total);
    issue = iss;
}

std::string Magazine::getType() const {
    return "Magazine";
}

void Magazine::print() const {
    std::cout << "===== Magazine =====" << std::endl;
    printBaseInfo();
    std::cout << "Issue: " << issue << std::endl;
}

// 杂志归还
void Magazine::returnOne() {
    Book::returnOne();
    std::cout << "  >> Magazine: returned to periodical reading area, sorted by issue." << std::endl;
}
// ========== 派生类EBook ==========
EBook::EBook() : fileSize(0) {}

void EBook::initEBook(const std::string& n, const std::string& id, const std::string& pub, double p, int total, double fs, const std::string& fmt)
{
    initData(n, id, pub, p, total);
    fileSize = fs;
    format = fmt;
}

std::string EBook::getType() const {
    return "E-Book";
}

void EBook::print() const {
    std::cout << "===== E-Book =====" << std::endl;
    printBaseInfo();
    std::cout << "File size: " << fileSize << " MB" << std::endl;
    std::cout << "Format: " << format << std::endl;
}

// 电子书归还
void EBook::returnOne() {
    Book::returnOne();
    std::cout << "  >> E-resource: access revoked, available for next borrow immediately." << std::endl;
}