#include <iostream>
using std::cout;
using std::endl;

class Base //构造函数用protected修饰的类是抽象类
{
public:
protected:
    Base()
    {
        cout << "Base()" << endl;
    }
};

class Derived
: public Base
{
public:
    Derived()   //派生类的构造函数如果不显示调用基类的构造函数的话，就会自动调用默认的无参构造函数
                //最好显示调用基类的构造函数，增强代码的可读性和鲁棒性
    : Base()
    {
        cout << "Derived()" << endl;
    }
};

void test()
{
    //Base base;//error
    Derived derievd;
}

int main()
{
    test();
    return 0;
}

