#include "Computer.h"
#include <iostream>
#include <string.h>

using namespace std;

Computer::Computer(const char* brand, float price)
: _brand(new char[strlen(brand) + 1]())
, _price(price)
{
    cout << "Computer(const char *, float)" << endl;
    strcpy(_brand, brand);
}

void Computer::setBrand(const char *brand)
{
    strcpy(_brand, brand);
    cout << "setBrand(const char *)" << endl;
}

void Computer::setPrice(float price)
{
    _price = price;
    cout << "setPrice(float)" << endl;
}

void Computer::print()
{
    if(_brand)
    {
    cout << "_brand = " << _brand << endl
        << "_price = " << _price << endl;
    }
}

Computer::~Computer()
{
   cout << "~Computer" << endl;
   if(_brand)
   {    
   delete []_brand;
   _brand = nullptr;
   }
}
