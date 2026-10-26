#include "Student.h"

// ========== Student基类实现 ==========
Student::Student() : borrowCount(0), maxBorrow(3) {
    for (int i = 0; i < MAX_BORROW; i++)
        borrowBooks[i] = nullptr;
}

Student::~Student() {}

void Student::initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor)
{
    stuId = id;
    stuName = name;
    department = dep;
    maxBorrow = maxBor;
    borrowCount = 0;
}

bool Student::borrowBook(Book* book)
{
    if (!book->getStatus())
    {
        std::cout << "[学生通道] Borrow failed: resource not available!" << std::endl;
        return false;
    }
    if (borrowCount >= maxBorrow)
    {
        std::cout << "[学生通道] Borrow failed: reached max borrow limit!" << std::endl;
        return false;
    }

    borrowBooks[borrowCount] = book;
    borrowCount++;
    book->borrowOne();
    std::cout << "[学生通道] Borrow success! Title: " << book->getBookName() << std::endl;
    return true;
}

bool Student::returnBook(Book* book)
{
    for (int i = 0; i < borrowCount; i++)
    {
        if (borrowBooks[i]->getIsbn() == book->getIsbn())
        {
            book->returnOne();
            for (int j = i; j < borrowCount - 1; j++)
                borrowBooks[j] = borrowBooks[j + 1];
            borrowBooks[borrowCount - 1] = nullptr;
            borrowCount--;
            std::cout << "[学生通道] Return success! Title: " << book->getBookName() << std::endl;
            return true;
        }
    }
    std::cout << "[学生通道] Return failed: you didn't borrow this resource." << std::endl;
    return false;
}

void Student::showStudentInfo()
{
    std::cout << "\n===== User Info =====" << std::endl;
    std::cout << "Identity: Student" << std::endl;
    std::cout << "ID: " << stuId << std::endl;
    std::cout << "Name: " << stuName << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Max Borrow: " << maxBorrow << " items" << std::endl;
    std::cout << "Currently Borrowed: " << borrowCount << " items" << std::endl;
    std::cout << "Borrowed list:" << std::endl;
    for (int i = 0; i < borrowCount; i++)
    {
        std::cout << "  " << borrowBooks[i]->getBookName() << " | ISBN: " << borrowBooks[i]->getIsbn() << std::endl;
    }
}