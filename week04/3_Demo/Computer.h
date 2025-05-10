#ifndef __COMPUTER_H__
#define __COMPUTER_H__

#include <string>
using std::string;

class Computer
{
public:
    void setBrand(string brand);
    void setPrice(float price);
    void print();

private:
    string _brand;
    float _price;
};

#endif
