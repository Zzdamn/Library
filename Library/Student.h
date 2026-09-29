#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "Book.h"

const int MAX_BORROW = 3;

class Student
{
private:
    std::string stuId;
    std::string stuName;
    std::string department;
    int maxBorrow;
    int borrowCount;
    Book* borrowBooks[MAX_BORROW];
public:
    void initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor);
    bool borrowBook(Book& book);
    bool returnBook(Book& book);
    void showStudentInfo();
};

#endif