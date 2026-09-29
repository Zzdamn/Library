#include "Book.h"
#include <iostream>
#pragma execution_character_set("utf-8")

using namespace std;

void Book::initData(const std::string& n, const std::string& id, const std::string& pub, double p, int pg, bool sta)
{
    bookName = n;
    isbn = id;
    publisher = pub;
    price = p;
    pageNum = pg;
    isAvailable = sta;
}

std::string Book::getIsbn()
{
    return isbn;
}

std::string Book::getBookName()
{
    return bookName;
}

void Book::setStatus(bool s)
{
    isAvailable = s;
}


bool Book::getStatus()
{
    return isAvailable;
}

void Book::print()
{
    cout << "Book Name: " << bookName << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Price: " << price << endl;
    cout << "Pages: " << pageNum << endl;
    if (isAvailable)
    {
        cout << "Status: Available" << endl;
    }
    else
    {
        cout << "Status: Not Available" << endl;
    }
}

bool Book::verifyIsbn()
{
    for (size_t i = 0; i < isbn.length(); i++)
    {
        if (isbn[i] < '0' || isbn[i] > '9')
        {
            return false;
        }
    }
    return true;
}