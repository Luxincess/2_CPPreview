#include <iostream>
using std::cout;
using std::endl;

template <typename ...Args>
void print(Args ...args)
{
    cout << "sizeof(Args) = " << sizeof...(Args) << endl;
    cout << "sizeof(args) = " << sizeof...(args) << endl;
}

void test()
{
    print();
    print(1, "hello");
    print("hello", 3.3, true);
    print("hello", 3.3, true, 4.4, 5.5, "world");
}

int main()
{
    test();
    return 0;
}

