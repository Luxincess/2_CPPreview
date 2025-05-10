#include <iostream>
#include <limits>
using namespace std;

class Complex
{
    friend ostream &operator<<(ostream &os, const Complex &rhs);
    friend istream &operator>>(istream &is, Complex &rhs);
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

ostream &operator<<(ostream &os, const Complex &rhs)
{
    cout << "ostream &operator<<(ostream &, const Complex &)" << endl;
    if(rhs._dreal == 0 && rhs._dimag == 0)
    {
        os << 0 << endl;
    }
    else if(rhs._dreal == 0)
    {
        os << rhs._dimag << "i" << endl;
    }
    else
    {
        os << rhs._dreal;
        if(rhs._dimag > 0)
        {
            os << "+" << rhs._dimag << "i" << endl;
        }
        else if(0 == rhs._dimag)
        {
            os << endl;
        }
        else
        {
            os << "-" << (-1)*rhs._dimag << endl;
        }
    }
    return os;
}

void readDouble(istream &is, double &number)
{
    while(is >> number, !is.eof())
    {
        if(is.bad())
        {
            cout << "stream is bad" << endl;
            return;
        }
        else if(is.fail())
        {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "pls input double data" << endl;
        }
        else
        {
            cout << "number = " << number << endl;
            break;
        }
    }
}

istream &operator>>(istream &is, Complex &rhs)
{
    cout << "istream &operator>>(istream &, Compelx &)" << endl;
    readDouble(is, rhs._dreal);
    readDouble(is, rhs._dimag);
    return is;
}

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
    if(_dreal == 0 && _dimag == 0)
    {
        cout << 0 << endl;
    }
    else if(_dreal == 0)
    {
        cout << _dimag << "i" << endl;
    }
    else
    {
        cout << _dreal;
        if(_dimag > 0)
        {
            cout << "+" << _dimag << "i" << endl;
        }
        else if(0 == _dimag)
        {
            cout << endl;
        }
        else
        {
            cout << "-" << (-1)*_dimag << endl;
        }
    }
}

Complex::~Complex()
{
    cout << "~Complex()" << endl;
}

void test()
{
    Complex c1(1,3);
    cout << c1 << endl;
    Complex c2;
    cin >> c2;
    cout << "c2 = " << c2 << endl;

}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

