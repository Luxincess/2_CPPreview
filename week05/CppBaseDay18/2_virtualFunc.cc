#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    virtual 
    void func(int val = 1)
    {
        cout << "A->" << val << endl;
    }
private:
    long _a;
};

class B
: public A
{
public:
    virtual
    void func(int val = 10)
    {
        cout << "B->" << val << endl;
    }
private:
    long _b;
};

void test()
{
    B b;
    A *p1 = &b;
    B *p2 = &b;
    p1->func(100);
    cout << endl;
    p1->func();
    p2->func();
    cout << endl;
    A &ref1 = b;
    B &ref2 = b;
    ref1.func();
    ref2.func();
}

int main()
{
    test();
    return 0;
}

