#include <iostream>
using namespace std;

class Empty//空类
{

};
void test()
{
    cout << "sizeof(Empty) = " << sizeof(Empty) <<endl;
    Empty em1;
    Empty em2;
    Empty em3;
    printf("&em1 = %p\n", &em1);
    printf("&em2 = %p\n", &em2);
    printf("&em3 = %p\n", &em3);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

