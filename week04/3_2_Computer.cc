#include <string>
#include <iostream>
using namespace std;

class Computer
{
public:
    inline
    void setBrand(string brand)
    {
        _brand = brand;
    }
    inline
    void setPrice(float price)
    {
        _price = price;
    }
    inline
    void print()
    {
        cout << "brand = " << _brand << endl
             << "price = " << _price << endl;
    }
private:
    string _brand; //品牌名
    float _price; //价格
};

int main(int argc, char* argv[])
{
    /* string brand = "Thinkpad"; */
    /* float price = 5500; */
    Computer com;
    /* com.setBrand(brand); */
    /* com.setPrice(price); */
    com.setBrand("Thinkpad");
    com.setPrice(5500);
    com.print();
    return 0;
}

