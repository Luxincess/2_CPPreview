#include<stdio.h>
#include <iostream>

using std::endl;
using std::cout;

int number = 1;
namespace wd
{
int number = 20;
void show(int number)
{
    cout << "形参number = " << number << endl;
    cout << "wd中的number = " << wd::number << endl;
    cout << "全局变量number = " << ::number << endl;

}
}//end of namespace wd 

int main(int argc, char* argv[])
{
    int value = 300;
    wd::show(value);
    return 0;
}

