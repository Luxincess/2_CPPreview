#include <string>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
using std::string;

template <class T>
T add(T x, T y)
{
    cout << "T add(T, T)" << endl;
    return x+y;
}

template <class T>
T add(T x, T y, T z)
{
    cout << "T add(T, T, T)" << endl;
    return x + y + z;
}
//* 函数模板可以和函数模板之间形成重载
//* 函数模板可以和普通函数之间形成重载
//* 默认情况下，普通函数优于函数模板执行
// int add(int x, int y)
// {
//     cout << "int add(int, int)" << endl;
//     return x + y;
// }

template <>   //* 模板参数列表为空，表示模板的特化   全特化与偏特化
const char *add<const char *>(const char *pstr1, const char *pstr2)
{
    cout << "const char *add(const char *, const char *)" << endl;
    char *ptemp = new char[strlen(pstr1) + strlen(pstr2) + 1]();
    strcpy(ptemp, pstr1);
    strcat(ptemp, pstr2);
    return ptemp;   
}



void test()
{
    int ia = 3, ib = 4, ic  = 5;
    double da = 3.3, db = 4.4;
    char ca = 'a', cb  = 1;
    string s1 ("hello");
    string s2("world");
    cout << "add(ia, ib) = " << add(ia, ib) << endl;
    cout << "add(ia, ib, ic) = " << add(ia, ib, ic) << endl;
    cout << "add(da, db) = " << add<double>(da, db) << endl;
    cout << "add(ia, ib) = " << add<int>(ia, ib) << endl;
    cout << "add(ca, cb) = " << add(ca, cb) << endl;
    cout << "add(s1, s2) = " << add(s1, s2) << endl;

    //cout << "add(ia, db) = " << add(ia, db) << endl;      //*类型推导失败

    cout << endl;
    const char *pstr1 = "hello";
    const char *pstr2 = "world";
    cout << "add(pstr1, pstr2) = " << add(pstr1, pstr2) << endl;

}

int main()
{
    test();
    return 0;
}

