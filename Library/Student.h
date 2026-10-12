#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Book.h"

const int MAX_BORROW = 3; // 原有常量保留

class Student
{
private:
    // 所有原有变量名完全保留
    std::string stuId;
    std::string stuName;
    std::string department;
    int maxBorrow;
    int borrowCount;
    Book* borrowBooks[MAX_BORROW]; // 基类指针，可指向任意子类对象，支持多态

public:
    Student();
    // 原有函数名完全保留
    void initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor);
    bool borrowBook(Book* book); // 参数改为基类指针，兼容所有子类
    bool returnBook(Book* book);
    void showStudentInfo();
};

#endif