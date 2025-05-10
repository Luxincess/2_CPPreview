#include <iostream>
using std::cout;
using std::endl;

void print()
{
    cout << endl;
}

template <class T,typename ...Args>   //* ...位于Args 和 args的左边叫做打包
void print(T t1, Args ...args)       //* ...位于args右边叫做解包
{
    cout << t1 << " ";
    print(args...);                 //* 递归的调用，一个参数一个参数的解，最后调用print()
}

void test()
{
    // print();
    print("hello", 1, true);
}

int main()
{
    test();
    return 0;
}

