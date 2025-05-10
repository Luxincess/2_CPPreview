#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }
    void print() const
    {
        cout << "void A::print()" << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "B()" << endl;
    }
    void print() const
    {
        cout << "void B::show()" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
};

class C
{
public:
    C()
    {
        cout << "C()" << endl;
    }

    void print() const
    {
        cout << "void C::display()" << endl;
    }

    ~C()
    {
        cout << "~C()" << endl;
    }
};

class D
: public A
, public B
, public C
{
public:
    D()
    {
        cout << "D()" << endl;
    }
    ~D()
    {
        cout << "~D()" << endl;
    }
};

void test()
{
    D d;
    d.A::print();
    d.B::print();
    d.C::print();
}

int main()
{
    test();
    return 0;
}

