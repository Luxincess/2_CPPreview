#include <iostream>
using namespace std;

class FunctionObject
{
public:
    FunctionObject();
    int operator()(int x, int y);
    int operator()(int x, int y, int z);
    void print() const;
private:
    int _cnt; //函数对象的状态
};

int add(int x, int y)
{
    cout << "int add(int, int)" << endl;
    static int cnt = 0;
    ++cnt;
    return x + y;
}

FunctionObject::FunctionObject()
: _cnt(0)
{
    cout << "FunctionObject()" << endl;
}

int FunctionObject::operator()(int x, int y)
{
    cout << "int operator()(int, int)" << endl;
    ++_cnt;
    return x + y;
}

int FunctionObject::operator()(int x, int y, int z)
{
    cout << "int operator()(int, int, int)" << endl; 
    ++_cnt;
    return x*y*z;
}

void FunctionObject::print() const
{
    cout << "print()" << endl;
}

void test()
{
    int a = 3, b =4, c =5;
    FunctionObject fo;
    cout << "fo(a, b) = " << fo.operator()(a, b) << endl;
    cout << "fo(a, b,c) = " << fo.operator()(a,b,c) << endl;

    fo.print();
    cout << "add(a,b) = " << add(a,b) << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

