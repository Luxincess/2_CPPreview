#include <iostream>
using namespace std;

void test()
{
    int number = 10;
    printf("sizeof(number) = %lu\n", sizeof(number));
    printf("sizeof number = %lu\n", sizeof number );
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

