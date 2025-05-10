#include "Computer.h"
#include <iostream>
#include <string.h>
using namespace std;

float Computer::_totalPrice = 0;

Computer::Computer(const char *brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
    cout << "Computer(const char *, float)" << endl;
    strcpy(_brand, brand);
    _totalPrice += _price;
}

Computer::Computer(const Computer &rhs)
: _brand(new char[strlen(rhs._brand) + 1]())
, _price(rhs._price)
{
    cout << "Computer(const Computer &rhs)" << endl;
    strcpy(_brand, rhs._brand);
}

Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Computer &operator=(const Computer &)" << endl;
    if(this != &rhs)
    {
        delete []_brand;
        _brand = nullptr;
        _brand = new char[strlen(rhs._brand) + 1]();
        strcpy(_brand, rhs._brand);
        _price = rhs._price;
    }
    return *this;
}

void Computer::setBrand(const char *brand)
{
    strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
    _price = price;
}

void Computer::print()
{
    cout << "void print()" << endl;
    cout << "brand = " << _brand << endl
         << "price = " << _price << endl;
}

void Computer::print() const
{
    cout << "void print() const" << endl;
    cout << "brand = " << _brand << endl
         << "price = " << _price << endl;
}

Computer::~Computer()
{
    cout << "~Computer()" << endl;
    if(_brand)
    {
        delete []_brand;
        _brand = nullptr;
    }
}

void Computer::printTotalPrice()
{
    cout << "void printTotalPrice()" << endl;
    cout << "totalPrice = " << _totalPrice << endl;
}
