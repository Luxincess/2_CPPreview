#include <string.h>
#include <iostream>
using namespace std;

class Computer
{
public:
    void setBrand(const char *brand)
    {
        strcpy(_brand,brand);
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

private:
    char _brand[20];
    float _price;

};

int main(int argc, char* argv[])
{
    Computer com;
    com.setBrand("Thinkpad");
    com.setPrice(5500);
    com.print();
    /* com._price = 5500; */
    return 0;
}

