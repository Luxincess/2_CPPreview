#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
    Base(long member = 0)
    : _member(member)
    {
        cout << "Base(long = 0)" << endl;
    }

    void print()
    { 
        cout << "Base::_member = " << _member << endl;
    }

    virtual
    ~Base()
    {

    }
protected:
    long _member;
};

class Derived
: public Base
{
public:
    Derived(long member, long member2)
    : Base(member)
    , _member(member2)
    {

    }

    void print(int x)
    {
        cout << "x = " << x << endl;
        cout << "void Derived::print(int)" << endl;
        cout << "_member = " << _member << endl;
        cout << "Base::_member = " << Base::_member << endl; //被隐藏 通过类名➕作用域限定符调用
    }

    ~Derived()
    {

    }
private:
    long _member;
};

void test()
{
    Derived d(100,200);
    d.Base::print(); //基类中的print被隐藏，但是不是直接删除
    d.print(22);
    //d.print();//error
}

int main()
{
    test();
    return 0;
}

