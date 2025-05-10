#include <memory>
#include <iostream>
using std::cout;
using std::endl;
using std::auto_ptr;

void test()
{
    int *pInt = new int(10);
    auto_ptr<int> ap(pInt); //智能指针，尖括号里面显示托管指针的类型 c++17中已经废弃
    cout << "*pInt = " << *pInt << endl;
    cout << "*ap = " << *ap << endl;
    cout << "pInt = " << pInt << endl; 
    cout << "ap.get() = " << ap.get() << endl;

    cout << endl;
    auto_ptr<int> ap2 = ap; //拷贝构造函数 所有权转移
    cout << "*ap2 = " << *ap2 << endl;
    cout << "*ap = " << *ap << endl;
}

int main()
{
    test();
    return 0;
}

