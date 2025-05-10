#include <iostream>
using namespace std;

class Complex
{
    //友元
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
public:
    Complex(double dreal = 0.0, double dimag = 0.0);
    ~Complex();
    //复合赋值运算符的重载
    Complex &operator+=(const Complex &rhs);
    double getReal() const;
    double getImag() const;
    void print() const;
private:
    double _dreal;
    double _dimag;
};


Complex::Complex(double dreal, double dimag)
: _dreal(dreal)
, _dimag(dimag)
{
    cout << "Complex::Complex(double, double)" << endl;
}

Complex::~Complex()
{
    cout << "~Complex()" << endl;
}

Complex &Complex::operator+=(const Complex &rhs)
{
    cout << "Complex &Complex::operator+=(const Complex &)" << endl;
    _dreal += rhs._dreal;
    _dimag += rhs._dimag;
    return *this;
}

double Complex::getReal() const
{
    return _dreal;
}

double Complex::getImag() const
{
    return _dimag;
}

void Complex::print() const
{
    cout << _dreal << "+" << _dimag << "i" << endl;
}

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    Complex com(lhs._dreal+rhs._dreal, lhs._dimag+rhs._dimag);
    return com;
}

void test()
{
    Complex c1(1,3);
    cout << "c1 = ";
    c1.print();

    cout << endl;
    Complex c2(2,6);
    cout << "c2 = ";
    c2.print();

    cout << endl;
    Complex c3 = c1 + c2;
    cout << "c3 = ";
    c3.print();

    cout << endl;
    c3 += c1;
    cout << "c3 = ";
    c3.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

