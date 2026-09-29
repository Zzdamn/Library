#include <windows.h>
#include "Book.h"
#include "Student.h"
#include <iostream>
#pragma execution_character_set("utf-8")

using namespace std;

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Book bk1, bk2;
    bk1.initData("C++ Basics", "1145141919810", "People's Posts & Telecom Press", 49.5, 514, true);
    bk2.initData("Data Structures", "9876543210", "Higher Education Press", 38, 320, true);

    cout << "==== Original Book Status ====" << endl;
    bk1.print();
    cout << endl;
    bk2.print();
    cout << endl;

    Student stu;
    stu.initStudent("20240001", "Zhang San", "Computer Science", 3);

    stu.borrowBook(bk1);
    stu.borrowBook(bk2);

    cout << "\n==== Student Info (after borrowing) ====" << endl;
    stu.showStudentInfo();

    cout << "\n==== Book Status (after borrowing) ====" << endl;
    bk1.print();
    bk2.print();

    cout << "\n----Attempt to borrow C++ Basics again----" << endl;
    stu.borrowBook(bk1);

    cout << "\n----Returning: Data Structures----" << endl;
    stu.returnBook(bk2);

    cout << "\n==== Student Info (after return) ====" << endl;
    stu.showStudentInfo();

    cout << "\n==== Book bk2 Status (after return) ====" << endl;
    bk2.print();

    return 0;
}