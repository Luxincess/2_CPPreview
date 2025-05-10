#include <iostream>
using namespace std;

int number = 1; //匿名命名空间的全局变量
namespace lsx
{
int number = 20;
class Example
{
public:
    Example(int value)
    : number(value)
    {

    }
    void print(int number)
    {
        cout << "形参numebr = " << number << endl;
        cout << "数据成员number = " << this->number << endl;
        cout << "数据成员number = " << Example::number << endl;
        cout << "命名空间中的number = " << lsx::number << endl;
        cout << "匿名命名空间中的number = " << ::number << endl;
    }
private:
    int number;
};//end of class Example
}//end of namespace lsx


void test()
{
    int ix = 4000;
    lsx::Example ex(300);
    ex.print(ix);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

