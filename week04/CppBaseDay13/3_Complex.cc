#include <iostream>
using namespace std;

class Complex
{
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
public:
    Complex(double dreal = 0.0, double dimag = 0.0);
    Complex &operator+=(const Complex &rhs);
    Complex &operator++();
    Complex operator++(int);
    double getReal() const;
    double getImag() const;
    void print() const;
    ~Complex();
private:
    double _dreal;
    double _dimag;
};

Complex operator+(const Complex &lhs, const Complex &rhs)
{
    cout << "Complex operator+(const Complex &, const Complex &)" << endl;
    return Complex(lhs._dreal + rhs._dreal, lhs._dimag + rhs._dimag);
}

Complex::Complex(double dreal, double dimag)
: _dreal(dreal)
, _dimag(dimag)
{
    cout << "Complex(double = 0.0, double = 0.0)" <<endl;
}

Complex &Complex::operator+=(const Complex &rhs)
{
    cout << "Complex &operator+=(const Complex &)" << endl;
    _dreal += rhs.getReal();
    _dimag += rhs.getImag();
    return *this;
}

Complex &Complex::operator++()
{
    cout << "Complex &operator++()" << endl;
    _dreal ++;
    _dimag ++;
    return *this;
}

Complex Complex::operator++(int)
{
    cout << "Complex operator++(int)" << endl;
    /* Complex temp(this->_dreal, this->_dimag); */
    Complex temp(*this);//拷贝构造函数
    _dreal ++;
    _dimag ++;
    return temp;
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
    cout << _dreal << "+" << _dimag <<"i" << endl;
}

Complex::~Complex()
{
    cout << "~Complex()" << endl;
}

void test()
{
    Complex c1(1,3);
    c1.print();
    Complex c2(2,6);
    c2.print();
    cout << endl;
    Complex c3 = c1 + c2;
    c3.print();
    cout << endl;
    (c3++).print();
    c3.print();

    cout << endl;
    (++c3).print();
    c3.print();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

