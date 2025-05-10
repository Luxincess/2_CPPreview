#include <iostream>
using std::cout;
using std::endl;

class Base //定义了纯虚函数的类称作抽象类，抽象类不能创建对象，但是可以创建抽象类的指针或者引用
{
public:
    virtual void show() const = 0; //纯虚函数
    virtual void print() const = 0;
};

class Derived //如果派生类中有纯虚函数没有实现，那么派生类也是一个抽象类
: public Base
{
public:
    void show() const override //加上override关键字明确表示覆盖基类中的对应函数
    {
        cout << "void Derived::show() const" << endl; 
    }
};

class Derived2
: public Derived
{
public:
    virtual
    void print() const
    {
        cout << "void Derived2::print() const" << endl;
    }
};

void test()
{
    Derived2 derived2;
    derived2.print();
    derived2.show();
    cout << endl;
    Base *pbase = &derived2;
    pbase->show();
    pbase->print();

    Derived *pderived = &derived2;
    pderived->show();
    pderived->print();
}

int main()
{
    test();
    return 0;
}

