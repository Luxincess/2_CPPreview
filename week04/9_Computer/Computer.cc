#include "Computer.h"
#include <iostream>
#include <string.h>
using namespace std;

Computer::Computer(const char *brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
    strcpy(_brand, brand);
    cout << "Computer(cosnt char *, float)" << endl;
}

Computer::Computer(const Computer &rhs)
: _brand(new char[strlen(rhs._brand) + 1]())
, _price(rhs._price)
{
    strcpy(_brand, rhs._brand);
    cout << "Computer(cosnt Computer &)" << endl;
}

Computer &Computer::operator=(const Computer &rhs)
{
    cout << "Compuer &operator=(cosnt Computer &)" << endl;
    if(this != &rhs)
    {
        delete []_brand;
        _brand = nullptr;

        this->_brand = new char[strlen(rhs._brand) + 1]();
        strcpy(this->_brand, rhs._brand);
        this->_price = rhs._price;
    }
    return *this;
}

void Computer::setBrand(const char *brand)
{
    delete []_brand;
    _brand = nullptr;
    _brand = new char[strlen(brand) + 1]();
    strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
   _price = price; 
}

void Computer::print()
{
    if(_brand)
    {
        cout << "brand = " << _brand << endl
             << "price = " << _price << endl;
    }
}

Computer::~Computer()
{
    if(_brand)
    {
        delete []_brand;
        _brand = nullptr;
    }
    cout << "~Computer()" << endl;
}
