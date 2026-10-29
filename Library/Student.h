#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <vector>   // 实验五：引入vector容器头文件
#include "Book.h"

class Student
{
protected:
    std::string stuId;
    std::string stuName;
    std::string department;
    int maxBorrow;
    // 实验五：替换固定数组为vector容器，动态管理借阅记录
    std::vector<Book*> borrowBooks;

public:
    Student();
    virtual ~Student();

    void initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor);
    virtual bool borrowBook(Book* book);
    virtual bool returnBook(Book* book);
    void showStudentInfo();
};

#endif