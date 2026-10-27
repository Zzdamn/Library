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
        std::cout << "[教师通道] Borrow failed: resource not available." << std::endl;// 璧勬簮涓嶅彲鍊?
        return false;
    }
    if (borrowCount >= maxBorrow)
    {
        std::cout << "[教师通道] Borrow failed: reached teacher borrow limit." << std::endl;// 杈惧埌鏁欏笀鏈�澶у�熼槄閲?
        return false;
    }

    borrowBooks[borrowCount] = book;
    borrowCount++;
    book->borrowOne();
    std::cout << "[教师通道] Borrow success: " << book->getBookName() << std::endl;// 鍊熼槄鎴愬姛
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
            std::cout << "[教师通道] Return success: " << book->getBookName() << std::endl;// 褰掕繕鎴愬姛
            return true;
        }
    }
    std::cout << "[教师通道] Return failed: you did not borrow this resource." << std::endl;// 褰掕繕澶辫触锛屾湭鍊熼槄璇ヨ祫婧?
    return false;
}