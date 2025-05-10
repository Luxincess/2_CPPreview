#include <string>
#include <iostream>
using namespace std;

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
int main(int argc, char* argv[])
{
    Computer com;
    com.setBrand("Thinkpad");
    com.setPrice(5500);
    com.print();
    return 0;
}

