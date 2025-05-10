#include <iostream>
using std::endl;
using std::cout;

template <class T, short kSize = 10>  //* 非类型参数必须是整型
T func(T x, T y)
{
    return x * y * kSize;
}

void test()
{
    int ia = 10, ib = 20;
    double da = 3.3, db = 4.4;
    cout << "func(ia, ib) = " << func<int>(ia, ib) << endl;
    cout << "func(ia, ib) = " << func<int, 40>(ia, ib) << endl;
    cout << "func(da, db) = " << func<int>(da, db) << endl;
} 

int main()
{
    test();
    return 0;
}

