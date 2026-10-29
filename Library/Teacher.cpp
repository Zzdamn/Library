#pragma execution_character_set("utf-8")
#include "Teacher.h"

Teacher::Teacher() {
    maxBorrow = 10;
}

void Teacher::initTeacher(const std::string& id, const std::string& name, const std::string& dep) {
    stuId = id;
    stuName = name;
    department = dep;
    maxBorrow = 10;
    borrowBooks.clear();
}

bool Teacher::borrowBook(Book* book) {
    if (!book->getStatus())
    {
        std::cout << "[教师通道] Borrow failed: resource not available." << std::endl;
        return false;
    }
    if (borrowBooks.size() >= maxBorrow)
    {
        std::cout << "[教师通道] Borrow failed: reached teacher borrow limit." << std::endl;
        return false;
    }

    borrowBooks.push_back(book);
    book->borrowOne();
    std::cout << "[教师通道] Borrow success: " << book->getBookName() << std::endl;
    return true;
}

bool Teacher::returnBook(Book* book) {
    for (auto it = borrowBooks.begin(); it != borrowBooks.end(); ++it)
    {
        if ((*it)->getIsbn() == book->getIsbn())
        {
            book->returnOne();
            borrowBooks.erase(it);
            std::cout << "[教师通道] Return success: " << book->getBookName() << std::endl;
            return true;
        }
    }
    std::cout << "[教师通道] Return failed: you did not borrow this resource." << std::endl;
    return false;
}