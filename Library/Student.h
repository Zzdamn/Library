#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Book.h"

const int MAX_BORROW = 10; // 数组上限调大，兼容教师更多借阅量；学生默认仍为3本

class Student
{
protected: // 仅此处由private改为protected，供子类Teacher访问，原有变量名全部保留
    std::string stuId;
    std::string stuName;
    std::string department;
    int maxBorrow;
    int borrowCount;
    Book* borrowBooks[MAX_BORROW];

public:
    Student();
    virtual ~Student(); // 新增：虚析构函数，作为用户基类

    // 原有函数名完全保留，仅加virtual关键字
    void initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor);
    virtual bool borrowBook(Book* book);
    virtual bool returnBook(Book* book);
    void showStudentInfo();
};

#endif