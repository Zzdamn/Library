#include "Student.h"
#include <iostream>
#pragma execution_character_set("utf-8")
using namespace std;

void Student::initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor)
{
    stuId = id;
    stuName = name;
    department = dep;
    maxBorrow = maxBor;
    borrowCount = 0;
    for (int i = 0; i < MAX_BORROW; i++)
    {
        borrowBooks[i] = nullptr;
    }
}

bool Student::borrowBook(Book& book)
{
    if (!book.getStatus())
    {
        cout << "Borrow failed: book already borrowed!" << endl;
        return false;
    }
    if (borrowCount >= maxBorrow)
    {
        cout << "Borrow failed: reached max borrow limit!" << endl;
        return false;
    }

    borrowBooks[borrowCount] = &book;
    borrowCount++;
    book.setStatus(false);
    cout << "Borrow success! Title: " << book.getBookName() << endl;
    return true;
}

bool Student::returnBook(Book& book)
{
    for (int i = 0; i < borrowCount; i++)
    {
        if (borrowBooks[i]->getIsbn() == book.getIsbn())
        {
            book.setStatus(true);
            for (int j = i; j < borrowCount - 1; j++)
            {
                borrowBooks[j] = borrowBooks[j + 1];
            }
            borrowBooks[borrowCount - 1] = nullptr;
            borrowCount--;
            cout << "Return success! Title: " << book.getBookName() << endl;
            return true;
        }
    }
    cout << "Return failed: student didn't borrow this book!" << endl;
    return false;
}

void Student::showStudentInfo()
{
    cout << "======== Student Info ========" << endl;
    cout << "ID: " << stuId << endl;
    cout << "Name: " << stuName << endl;
    cout << "Department: " << department << endl;
    cout << "Max Borrow: " << maxBorrow << " books" << endl;
    cout << "Currently Borrowed: " << borrowCount << " books" << endl;
    if (borrowCount > 0)
    {
        cout << "Borrowed books list:" << endl;
        for (int i = 0; i < borrowCount; i++)
        {
            cout << "  " << borrowBooks[i]->getBookName() << " | isbn:" << borrowBooks[i]->getIsbn() << endl;
        }
    }
    else
    {
        cout << "No borrowed books" << endl;
    }
    cout << "========================" << endl;
}
