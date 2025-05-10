#include <iostream>
using std::cout;
using std::endl;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }
    A(int ia)
    : _ia(ia)
    {
        cout << "A(int)" << endl;
    }

    ~A()
    {
        cout <<"~A()" << endl;
    }
protected:
    int _ia;
};

class B
: virtual public A
{
public:
    B(int ia, int ib)
    : A(ia)
    , _ib(ib)
    {
        cout << "B(int, int)" << endl;
    }

    ~B()
    {
        cout << "~B()" << endl;
    }
protected:
    int _ib;
};

class C
: public B
{
public:
    C(int ia, int ib, int ic)
    : A(ia)
    , B(ia,ib)
    , _ic(ic)
    {
        cout << "C(int, int, int)" << endl;
    }

    void print() const
    {
        cout << "_ia = " << _ia << endl
             << "_ib = " << _ib << endl
             << "_ic = " << _ic << endl;
    }

    ~C()
    {
        cout << "~C()" << endl;
    }
private:
    int _ic;
};

void test()
{
    C c(10,20,30);  //B中的构造函数对A的初始化没有用到 在继承链上存在虚继承的基类，最底层的子类要负责完成该虚基类部分成员的构造
    c.print();
    B b(30,40); //用到对A的初始化
}

int main()
{
    test();
    return 0;
}

