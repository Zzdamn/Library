#include "Student.h"

// ========== Student基类实现 ==========
Student::Student() : maxBorrow(3) {}

Student::~Student() {
    // 实验五：vector会自动释放内存，仅清空容器，不释放Book对象（依赖关系，生命周期由Library管理）
    borrowBooks.clear();
}

void Student::initStudent(const std::string& id, const std::string& name, const std::string& dep, int maxBor)
{
    stuId = id;
    stuName = name;
    department = dep;
    maxBorrow = maxBor;
    borrowBooks.clear(); // 实验五：清空vector，重置借阅记录
}

bool Student::borrowBook(Book* book)
{
    if (!book->getStatus())
    {
        std::cout << "[学生通道] Borrow failed: resource not available!" << std::endl;
        return false;
    }
    // 实验五：用vector的size()获取当前借阅数量
    if (borrowBooks.size() >= maxBorrow)
    {
        std::cout << "[学生通道] Borrow failed: reached max borrow limit!" << std::endl;
        return false;
    }

    // 实验五：push_back将元素加入vector末尾，替代数组下标赋值
    borrowBooks.push_back(book);
    book->borrowOne();
    std::cout << "[学生通道] Borrow success! Title: " << book->getBookName() << std::endl;
    return true;
}

bool Student::returnBook(Book* book)
{
    // 实验五：使用迭代器遍历vector，对应begin()、end()、erase()函数
    for (auto it = borrowBooks.begin(); it != borrowBooks.end(); ++it)
    {
        if ((*it)->getIsbn() == book->getIsbn())
        {
            book->returnOne();
            // 实验五：erase删除指定迭代器位置的元素
            borrowBooks.erase(it);
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
    // 实验五：size()返回当前元素个数
    std::cout << "Currently Borrowed: " << borrowBooks.size() << " items" << std::endl;
    std::cout << "Borrowed list:" << std::endl;
    for (auto& b : borrowBooks)
    {
        std::cout << "  " << b->getBookName() << " | ISBN: " << b->getIsbn() << std::endl;
    }
}