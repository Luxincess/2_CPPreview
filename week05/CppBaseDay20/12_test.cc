#include <iostream>
using std::cout;
using std::endl;

int sum()  //! 使用递归时一定要注意终止条件，一是要设置终止条件，二是要设置正确的终止条件
{
    return 0;
}

//TODO 使用方才学习的模板参数包和函数参数包来计算 1 + 2 + 3 + ... + 10
template <class T, class ...Args>
int sum(T x, Args ...args)
{
    return x + sum(args...);
}
void test()
{
    cout << "sum(1,2,3,...,10) = "
         << sum(1,2,3,4,5,6,7,8,9,10) << endl;
}

int main()
{
    test();
    return 0;
}

