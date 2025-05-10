#include <iostream>
using namespace std;

class A
{
public:
    A(long ix = 0)
    : _ix(ix)
    {
        cout << "A(long = 0)" << endl;
    }

    void setX(long ix)
    {
        _ix = ix;
    }

    void print() const
    {
        cout << "A::_ix = " << _ix << endl;
    }
    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    long _ix;
};

class B
: virtual public A
{
public:
    B()
    {
        cout << "B()" << endl;
    }
    ~B()
    {
        cout << "~B()" << endl;
    }
};

class C
: virtual public A
{
public:
    C()
    {
        cout << "C()" << endl;
    }
    ~C()
    {
        cout << "~C()" << endl;
    }
};

class D
: public B
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
    cout << "sizeof(A) = " << sizeof(A) << endl;
    cout << "sizeof(B) = " << sizeof(B) << endl;
    cout << "sizeof(C) = " << sizeof(C) << endl;
    cout << "sizeof(D) = " << sizeof(D) << endl;
    cout << endl;
    D d;
    d.B::setX(10);
    d.B::print();

    cout << endl;   
    d.C::setX(20);
    d.C::print();

    //d.setX(100);
    d.print();

    A a(10);
    B b;
    C c;
    printf("B = %p\n", &b);
    printf("B = %lu\n", *(long *)&b);
    printf("C = %p\n", &c);
    printf("C = %lu\n", *(long *)&c);
    printf("D = %lu\n", *(long *)&d);
    printf("D = %lu\n",*(long *)(long *)&d + 1);
}

int main()
{
    test();
    return 0;
} 

