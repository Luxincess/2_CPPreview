#include <iostream>
using std::cout;
using std::endl;

namespace std
{//标准命名空间也是可以扩展的
struct MyStruct
{
int a;
double b;
};
}

namespace wh
{
void func();
}

namespace wd
{
void print()
{
    cout << "void wd::print()" << endl;
    wh::func();
}
}//end of wd

namespace wh
{
void display()
{
    cout << "void wh::display()" << endl;
    wd::print();
}

void func()
{
    cout << "void wh::func()" << endl;
}
}//end of namespace wh
int main(int argc, char* argv[])
{
    return 0;
}

