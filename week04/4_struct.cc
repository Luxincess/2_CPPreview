#include <string.h>
#include <iostream>
using namespace std;

struct Computer
{
    char _brand[20];
    float _price;
    void setBrand(const char *brand)
    {
        strcpy(_brand, brand);
    }
    void setPrice(float price)
    {
        _price = price;
    }
    void print()
    {
        cout << "brand = " << _brand << endl
             << "price = " << _price << endl;
    }
};

int main(int argc, char* argv[])
{
    Computer com;
    strcpy(com._brand, "mac");
    com._price = 5500;
    com.print();
    return 0;
}

