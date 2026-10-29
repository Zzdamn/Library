#include <iostream>
#include <string>
#include "Book.h"
#include "Student.h"
#include "Teacher.h"
#include "Library.h"

using namespace std;

int main()
{
    system("chcp 65001 > nul");
    Library lib;
    Student stu;
    Teacher tea;
    stu.initStudent("2025001", "Zhang San", "Computer Science", 3);// 学生最大借阅量3本
    tea.initTeacher("T2025001", "Li Teacher", "Computer Science");// 教师最大借阅量10本

    // 实验六：启动时先加载文件数据
    lib.loadFromFile("library_data.txt");

    // 如果加载失败（文件不存在），再使用预置数据
    if (lib.findResource("1001") == nullptr) {
        GeneralBook* b1 = new GeneralBook();
        b1->initGeneralBook("C++ Programming Basics", "1001", "PT Press", 49.5, 5, 514);
        lib.addResource(b1);

        Magazine* m1 = new Magazine();
        m1->initMagazine("Computer Journal", "2001", "CS Society", 30, 3, "2024 Issue 10");
        lib.addResource(m1);

        EBook* e1 = new EBook();
        e1->initEBook("Data Structures (eBook)", "3001", "Higher Education Press", 20, 10, 15.6, "PDF");
        lib.addResource(e1);
    }
    // 预置测试数据
    GeneralBook* b1 = new GeneralBook();
    b1->initGeneralBook("C++ Programming Basics", "1001", "PT Press", 49.5, 5, 514);
    lib.addResource(b1);

    Magazine* m1 = new Magazine();
    m1->initMagazine("Computer Journal", "2001", "CS Society", 30, 3, "2024 Issue 10");
    lib.addResource(m1);

    EBook* e1 = new EBook();
    e1->initEBook("Data Structures (eBook)", "3001", "Higher Education Press", 20, 10, 15.6, "PDF");
    lib.addResource(e1);// 电子资源
    stu.borrowBook(b1);// 学生借阅普通图书
    stu.borrowBook(m1);// 学生借阅杂志
    stu.borrowBook(e1);// 学生借阅电子资源
    cout << "\n--- Start returning ---" << endl;// 开始归还
    stu.returnBook(b1);// 归还普通图书
    cout << endl;
    stu.returnBook(m1);// 归还杂志
    cout << endl;
    stu.returnBook(e1);// 归还电子资源
    cout << "\n--- Teacher borrow and return ---" << endl;// 教师开始借阅归还
    tea.borrowBook(b1);// 教师借阅普通图书
    tea.borrowBook(m1);// 教师借阅杂志
    tea.borrowBook(e1);// 教师借阅电子资源
    cout << "\n--- Teacher returning ---" << endl;// 教师开始归还
    tea.returnBook(b1);// 归还普通图书
    cout << endl;
    tea.returnBook(m1);// 归还杂志
    cout << endl;
    tea.returnBook(e1);// 归还电子资源

    cout << "\nStudent max borrow: 3 items | Teacher max borrow: 10 item" << endl;// 学生最大借阅量3本，教师最大借阅量10本
    cout << "Student uses standard channel | Teacher uses exclusive channel" << endl;// 学生使用标准通道，教师使用专属通道

    int choice;
    while (true)
    {
        cout << "\n===== Library Management System =====" << endl;// 图书馆管理系统
        cout << "1. Add new resource" << endl;// 1. 增加新资源
        cout << "2. Increase resource count" << endl;// 2. 增加已有资源数量
        cout << "3. Show specific resource" << endl;// 3. 显示单个资源
        cout << "4. Show all resources" << endl;// 4. 显示所有资源
        cout << "5. Decrease resource count" << endl;// 5. 减少资源数量
        cout << "6. Delete a resource" << endl;// 6. 删除资源
        cout << "7. Student borrow resource" << endl;// 7. 学生借阅资源
        cout << "8. Student return resource" << endl;// 8. 学生归还资源
        cout << "9. Show student borrowing info" << endl;// 9. 显示学生借阅信息
        cout << "10. Teacher borrow resource" << endl;// 10. 教师借阅资源
        cout << "11. Teacher return resource" << endl;// 11. 教师归还资源
        cout << "12. Show teacher borrowing info" << endl;// 12. 显示教师借阅信息
        cout << "0. Exit" << endl;// 0. 退出
        cout << "Please enter option: ";// 请输入选项
        cin >> choice;

        if (choice == 0) break;

        string isbn, name, pub;
        int num, type;
        double price;
        Book* res;

        switch (choice)
        {
        case 1:
            cout << "Select resource type (1-General 2-Magazine 3-EBook): ";// 选择资源类型
            cin >> type;
            cout << "Enter ISBN: "; cin >> isbn;// 输入ISBN
            cout << "Enter title: "; cin >> name;// 输入书名
            cout << "Enter publisher: "; cin >> pub;// 输入出版社
            cout << "Enter price: "; cin >> price;// 输入价格
            cout << "Enter initial count: "; cin >> num;// 输入初始数量

            if (type == 1) {
                int page;
                cout << "Enter page count: "; cin >> page;// 输入页数
                GeneralBook* gb = new GeneralBook();
                gb->initGeneralBook(name, isbn, pub, price, num, page);
                lib.addResource(gb);
            }
            else if (type == 2) {
                string issue;
                cout << "Enter issue: "; cin >> issue;// 输入期号
                Magazine* mg = new Magazine();
                mg->initMagazine(name, isbn, pub, price, num, issue);
                lib.addResource(mg);
            }
            else if (type == 3) {
                double fs; string fmt;
                cout << "Enter file size (MB): "; cin >> fs;// 输入文件大小
                cout << "Enter file format: "; cin >> fmt;// 输入文件格式
                EBook* eb = new EBook();
                eb->initEBook(name, isbn, pub, price, num, fs, fmt);
                lib.addResource(eb);
            }
            else {
                cout << "Invalid type!" << endl;// 类型无效
            }
            break;

        case 2:
            cout << "Enter ISBN: "; cin >> isbn;// 输入ISBN
            cout << "Enter increment amount: "; cin >> num;// 输入增加数量
            lib.addResourceCount(isbn, num);
            break;

        case 3:
            cout << "Enter ISBN: "; cin >> isbn;// 输入ISBN
            lib.showResource(isbn);
            break;

        case 4:
            lib.showAllResources();
            break;

        case 5:
            cout << "Enter ISBN: "; cin >> isbn;
            cout << "Enter decrement amount: "; cin >> num;// 输入减少数量
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

        case 10:
            cout << "Enter ISBN to borrow: "; cin >> isbn;
            res = lib.findResource(isbn);
            if (res) tea.borrowBook(res);
            else cout << "Resource not found!" << endl;
            break;

        case 11:
            cout << "Enter ISBN to return: "; cin >> isbn;
            res = lib.findResource(isbn);
            if (res) tea.returnBook(res);
            else cout << "Resource not found!" << endl;
            break;

        case 12:
            tea.showStudentInfo();
            break;

        default:
            cout << "Invalid input, please choose again!" << endl;// 输入无效，请重新选
        }
    }
    lib.saveToFile("library_data.txt");

    cout << "System exited." << endl;// 系统已退出
    return 0;
}