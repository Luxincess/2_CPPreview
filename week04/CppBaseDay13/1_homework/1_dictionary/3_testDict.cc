#include <iostream>
#include <time.h>
#include "1_dict.h"
using namespace std;

void test()
{
    Dictionary dict;
    cout << time(0) << endl;
    //显然生成词典的过程更花时间 read耗时更多
    dict.read("The_Holy_Bible.txt");
    cout << time(0) << endl;
    dict.store("Generated_dict.txt");
    cout << time(0) << endl;
    return;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

