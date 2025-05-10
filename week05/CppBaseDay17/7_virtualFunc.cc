#include <iostream>
using std::cout;
using std::endl;

class Grandpa
{
public:
    Grandpa()
    {
        cout << "Grandpa()" << endl;
    }

    ~Grandpa()
    {
        cout << "~Grandpa()" << endl;
    }

    virtual void func1()
    {
        cout << "void Grandpa::func1()" << endl;
    }

    virtual void func2()
    {
        cout << "void Grandpa::func2()" << endl;
    }
};

class Father
: public Grandpa
{
public:
    Father()
    : Grandpa()
    {
        cout << "Father()" << endl;
        this->func1();
    }

    ~Father()
    {
        cout << "~Father()" << endl;
        func2();
    }

    virtual
    void func1() override
    {
        cout << "void Father::func1()" << endl;
    }

    virtual 
    void func2() override
    {
        cout << "void Father::func2()" << endl;
    }
};

class Son
: public Father
{
public:
    Son()
    : Father()
    {
        cout << "Son()" << endl;
    }

    ~Son()
    {
        cout << "~Son()" << endl;
    }

    virtual 
    void func1()
    {
        cout << "Son::func1()" << endl;
    }

    virtual
    void func2()
    {
        cout << "Son::func2()" << endl;
    }
};

void test()
{
    Son son;
}

int main()
{
    test();
    return 0;
}

