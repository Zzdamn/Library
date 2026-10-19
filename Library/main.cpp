#pragma execution_character_set("utf-8")
#include <iostream>
#include <string>
#include "Book.h"
#include "Student.h"
#include "Library.h"

using namespace std;

int main()
{
    Library lib;
    Student stu;
    stu.initStudent("2025001", "Zhang San", "Computer Science", 3);

    // 基类指针指向子类对象，多态的基础
    GeneralBook* b1 = new GeneralBook();
    b1->initGeneralBook("C++ Programming Basics", "1001", "PT Press", 49.5, 5, 514);
    lib.addResource(b1);

    Magazine* m1 = new Magazine();
    m1->initMagazine("Computer Journal", "2001", "CS Society", 30, 3, "2024 Issue 10");
    lib.addResource(m1);

    EBook* e1 = new EBook();
    e1->initEBook("Data Structures (eBook)", "3001", "Higher Education Press", 20, 10, 15.6, "PDF");
    lib.addResource(e1);

    // ===== 多态效果演示 =====
    cout << "===== Polymorphism Demo =====" << endl;
    // 1. 基类指针调用虚函数
    Book* ptr = b1;
    ptr->print();
    cout << endl;
    // 2. 基类引用+运算符重载多态
    cout << *m1 << endl;
    cout << *e1 << endl;

    int choice;
    while (true)
    {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Add new resource" << endl;
        cout << "2. Increase resource count" << endl;
        cout << "3. Show specific resource" << endl;
        cout << "4. Show all resources" << endl;
        cout << "5. Decrease resource count" << endl;
        cout << "6. Delete a resource" << endl;
        cout << "7. Student borrow resource" << endl;
        cout << "8. Student return resource" << endl;
        cout << "9. Show student borrowing info" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter option: ";
        cin >> choice;

        if (choice == 0) break;

        string isbn, name, pub;
        int num, type;
        double price;
        Book* res;

        switch (choice)
        {
        case 1:
            cout << "Select resource type (1-General 2-Magazine 3-EBook): ";
            cin >> type;
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter title: "; cin >> name;
            cout << "Enter publisher: "; cin >> pub;
            cout << "Enter price: "; cin >> price;
            cout << "Enter initial count: "; cin >> num;

            if (type == 1) {
                int page;
                cout << "Enter page count: "; cin >> page;
                GeneralBook* gb = new GeneralBook();
                gb->initGeneralBook(name, isbn, pub, price, num, page);
                lib.addResource(gb);
            }
            else if (type == 2) {
                string issue;
                cout << "Enter issue: "; cin >> issue;
                Magazine* mg = new Magazine();
                mg->initMagazine(name, isbn, pub, price, num, issue);
                lib.addResource(mg);
            }
            else if (type == 3) {
                double fs; string fmt;
                cout << "Enter file size (MB): "; cin >> fs;
                cout << "Enter file format: "; cin >> fmt;
                EBook* eb = new EBook();
                eb->initEBook(name, isbn, pub, price, num, fs, fmt);
                lib.addResource(eb);
            }
            else {
                cout << "Invalid type!" << endl;
            }
            break;

        case 2:
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter increment amount: "; cin >> num;
            lib.addResourceCount(isbn, num);
            break;

        case 3:
            cout << "Enter ISBN: "; cin >> isbn;
            lib.showResource(isbn);
            break;

        case 4:
            lib.showAllResources();
            break;

        case 5:
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter decrement amount: "; cin >> num;
            lib.reduceResourceCount(isbn, num);
            break;

        case 6:
            cout << "Enter ISBN: "; cin >> isbn;
            lib.deleteResource(isbn);
            break;

        case 7:
            cout << "Enter ISBN to borrow: "; cin >> isbn;
            res = lib.findResource(isbn);
            if (res) stu.borrowBook(res);
            else cout << "Resource not found!" << endl;
            break;

        case 8:
            cout << "Enter ISBN to return: "; cin >> isbn;
            res = lib.findResource(isbn);
            if (res) stu.returnBook(res);
            else cout << "Resource not found!" << endl;
            break;

        case 9:
            stu.showStudentInfo();
            break;

        default:
            cout << "Invalid input, please choose again!" << endl;
        }
    }

    cout << "System exited." << endl;
    return 0;
}