#pragma execution_character_set("utf-8")
#include "Teacher.h"

Teacher::Teacher() {
    maxBorrow = 10;
    borrowCount = 0;
    for (int i = 0; i < MAX_BORROW; i++)
        borrowBooks[i] = nullptr;
}

void Teacher::initTeacher(const std::string& id, const std::string& name, const std::string& dep) {
    stuId = id;
    stuName = name;
    department = dep;
    maxBorrow = 10;
    borrowCount = 0;
}

bool Teacher::borrowBook(Book* book) {
    if (!book->getStatus())
    {
        std::cout << "[Teacher Channel] Borrow failed: resource not available." << std::endl;
        return false;
    }
    if (borrowCount >= maxBorrow)
    {
        std::cout << "[Teacher Channel] Borrow failed: reached teacher borrow limit." << std::endl;
        return false;
    }

    borrowBooks[borrowCount] = book;
    borrowCount++;
    book->borrowOne();
    std::cout << "[Teacher Channel] Borrow success: " << book->getBookName() << std::endl;
    return true;
}

bool Teacher::returnBook(Book* book) {
    for (int i = 0; i < borrowCount; i++)
    {
        if (borrowBooks[i]->getIsbn() == book->getIsbn())
        {
            book->returnOne();
            for (int j = i; j < borrowCount - 1; j++)
                borrowBooks[j] = borrowBooks[j + 1];
            borrowBooks[borrowCount - 1] = nullptr;
            borrowCount--;
            std::cout << "[Teacher Channel] Return success: " << book->getBookName() << std::endl;
            return true;
        }
    }
    std::cout << "[Teacher Channel] Return failed: you did not borrow this resource." << std::endl;
    return false;
}