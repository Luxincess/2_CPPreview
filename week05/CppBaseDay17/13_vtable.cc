#include <iostream>
using std::cout;
using std::endl;

//验证虚表
class Base
{
public:
    Base(long base = 0)
    : _base(base)
    {
        cout << "Base(long = 0)" << endl;
    }

    ~Base()
    {
        cout << "~Base()" << endl;
    }

    virtual 
    void func()
    {
        cout << "virtual void Base::func()" << endl;
    }

    virtual 
    void gunc()
    {
        cout << "virtual void Base::gunc()" << endl;
    }

    virtual 
    void hunc()
    {
        cout << "virtual void Base::hunc()" << endl;
    }        
private:
    long _base;
};

class Derived
: public Base
{
public:
    Derived(long base = 0, long derived = 0)
    :Base(base)
    , _derived(derived)
    {
        cout << "Derived(long = 0, long = 0)" << endl;
    }

    ~Derived()
    {
        cout << "~Derived()" << endl;
    }

    virtual
    void func()
    {
        cout << "virtual void Derived::func()" << endl;
    }

    virtual
    void gunc()
    {
        cout << "virtual void Derived::gunc()" << endl;
    }
    
    virtual
    void hunc()
    {
        cout << "virtual void Derived::hunc()" << endl;
    }    
private:
    long _derived;
};

void test()
{
    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;
    cout << endl;
    Derived d(10,20);
    printf("打印d的地址: %p\n", &d);
    printf("打印d的地址: %p\n", (long *)&d);
    printf("打印虚表的地址: %p\n", (long *)*(long *)&d);
    printf("打印第一个虚函数的入口地址: %p\n", (long *)*(long *)*(long *)&d);

    cout << endl;
    Derived d2(100,200);
    printf("打印d2的地址: %p\n", &d2);
    printf("打印d2的地址: %p\n", (long *)&d2);
    printf("打印虚表的地址: %p\n", (long *)*(long *)&d2);
    printf("打印第一个虚函数的入口地址: %p\n", (long *)*(long *)*(long *)&d2);

    cout << endl;
    typedef void (*pFunc)(); //函数指针
    pFunc f = (pFunc)*((long *)*(long *)&d);
    printf("打印第一个虚函数的地址: %p\n", f);
    f();

    cout << endl;
    pFunc f2 = (pFunc)*((long *)*(long *)&d + 1);
    printf("打印第二个虚函数的地址: %p\n", f2);
    f2();

    cout << endl;
    pFunc f3 = (pFunc)*((long *)*(long *)&d + 2);
    printf("打印第三个虚函数的地址: %p\n", f3);
    f3();

    cout << endl;
    //d2.Base::func(); 隐藏而不是直接删除
    cout << "_base = " << (long)*((long *)&d + 1) << endl;
    cout << "_derived = " << (long)*((long *)&d + 2) << endl;
}

int main()
{
    test();
    return 0;
}

