#include "Student.h"

Student::Student() : borrowCount(0), maxBorrow(MAX_BORROW) {
    for (int i = 0; i < MAX_BORROW; i++)
        borrowBooks[i] = nullptr;
}

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
    // 原有判断逻辑保留，接口兼容
    if (!book->getStatus())
    {
        std::cout << "Borrow failed: resource not available!" << std::endl;
        return false;
    }
    if (borrowCount >= maxBorrow)
    {
        std::cout << "Borrow failed: reached max borrow limit!" << std::endl;
        return false;
    }

    borrowBooks[borrowCount] = book;
    borrowCount++;
    book->borrowOne(); // 调用基类方法，可借数量-1
    std::cout << "Borrow success! Title: " << book->getBookName() << std::endl;
    return true;
}

bool Student::returnBook(Book* book)
{
    for (int i = 0; i < borrowCount; i++)
    {
        if (borrowBooks[i]->getIsbn() == book->getIsbn())
        {
            book->returnOne();
            // 前移数组元素
            for (int j = i; j < borrowCount - 1; j++)
                borrowBooks[j] = borrowBooks[j + 1];
            borrowBooks[borrowCount - 1] = nullptr;
            borrowCount--;
            std::cout << "Return success! Title: " << book->getBookName() << std::endl;
            return true;
        }
    }
    std::cout << "Return failed: you didn't borrow this resource." << std::endl;
    return false;
}

void Student::showStudentInfo()
{
    std::cout << "===== Student Info =====" << std::endl;
    std::cout << "ID: " << stuId << std::endl;
    std::cout << "Name: " << stuName << std::endl;
    std::cout << "Department: " << department << std::endl;
    std::cout << "Max Borrow: " << maxBorrow << " books" << std::endl;
    std::cout << "Currently Borrowed: " << borrowCount << " books" << std::endl;
    std::cout << "Borrowed books list:" << std::endl;
    for (int i = 0; i < borrowCount; i++)
    {
        std::cout << "  " << borrowBooks[i]->getBookName() << " | isbn: " << borrowBooks[i]->getIsbn() << std::endl;
    }
}