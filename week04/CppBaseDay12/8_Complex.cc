#include <iostream>
using namespace std;


class Complex
{
    friend Complex operator+(const Complex &lhs, const Complex &rhs);
public:
    Complex(double dreal = 0.0, double dimag = 0.0)
    : _dreal(dreal)
    , _dimag(dimag)
    {
        cout << "Complex(double = 0.0, double = 0.0)" << endl;
    }

    void print() const
    {
        cout << _dreal << "+" << _dimag << "i" << endl;
    }

    double getReal() const
    {
        return _dreal;
    }

    double getImag() const
    {
        return _dimag;
    }

    ~Complex()
    {
        cout << "~Complex()" << endl;
    }
private:
    double _dreal;
    double _dimag;
};

Complex operator+(const Complex &lhs,const Complex &rhs)
{
    Complex com(lhs._dreal + rhs._dreal, lhs._dimag + rhs._dimag);
    return com;
}
void test()
{
    Complex c1(1,3);
    cout << "c1 = " ;
    c1.print();

    cout << endl;
    Complex c2(2,6);
    cout << "c2 = ";
    c2.print();

    cout << endl;
    Complex c3 = c1 + c2;
    cout << "c3 = ";
    c3.print();
}


int main(int argc, char* argv[])
{
    test();
    return 0;
}

