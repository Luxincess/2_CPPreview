#include "Computer.h"
#include <iostream>
using namespace std;

void Computer::setBrand(string brand)
{
    _brand = brand;
}
void Computer::setPrice(float price)
{
    _price = price;
}
void Computer::print()
{
    cout << "brand = " << _brand << endl
         << "price = " << _price << endl;
}
