#include <iostream>
using std::cout;
using std::endl;

class Base1
{
public:
    virtual 
    void a()
    {
        cout << "virtual void Base1::a()" << endl;
    }

    virtual 
    void b()
    {
        cout << "virtual void Base1::b()" << endl;
    }

    virtual 
    void c()
    {
        cout << "virtual void Base1::c()" << endl;
    }
};

class Base2
{
public:
    virtual 
    void a()
    {
        cout << "virtual void Base2::a()" << endl;
    }

    virtual 
    void b()
    {
        cout << "virtual void Base2::b()" << endl;
    }

    void c() //注意这里只是普通的成员函数，所以没有动态多态
    {
        cout << "void Base2::c()" << endl;
    }

    void d()
    {
        cout << "void Base2::d()" << endl;
    }
};

class Derived1
: public Base1
, public Base2
{
public:
    virtual
    void a()
    {
        cout << "virtual void Derived1::a()" << endl;
    }

    void c() //虚函数
    {
        cout << "void Derived1::c()" << endl;
    }

    void d()
    {
        cout << "void Derived1::d()" << endl;
    }
};

class Derived2
: public Derived1
{
public:
    void c()
    {
        cout << "void Derived2::c()" << endl;
    }
};

void test()
{
    cout << "sizeof(Base1) = " << sizeof(Base1) << endl;
    cout << "sizeof(Base2) = " << sizeof(Base2) << endl;
    cout << "sizeof(Derived1) = " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) = " << sizeof(Derived2) << endl;

    cout << endl;
    Derived1 derived1;
    printf("&derived1 = %p\n", &derived1);

    cout << endl;
    Base1 *pbase1 = &derived1;
    printf("pbase1 = %p\n", pbase1);
    pbase1->a();  //Derived1
    pbase1->b(); //Base1
    pbase1->c(); //Derived1
    

    cout << endl;
    Base2 *pbase2 = &derived1;
    printf("pbase2 = %p\n", pbase2);
    pbase2->a();
    pbase2->b();
    pbase2->c();
    pbase2->d();

    cout << endl;
    Derived1 *pderived1 = &derived1;
    printf("pderived1 = %p\n", pderived1);
    pderived1->a();
    //pderived1->b();//error 有歧义
    pderived1->Base1::b();
    pderived1->Base2::b();
    pderived1->c();
    pderived1->d();

    cout << endl;
    Derived2 d2;
    Derived1 *pd1 = &d2;
    pd1->c();
    pd1->a();
    pd1->Base1::b();
    pd1->Base2::b();
    pd1->d();
}

int main()
{
    test();
    return 0;
}

