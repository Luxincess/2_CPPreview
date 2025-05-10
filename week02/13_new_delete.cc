#include<string.h>
#include<stdlib.h>
#include <iostream>
using namespace std;

void test()
{
    int *pret = (int*) malloc(sizeof(int));
    memset(pret,0,sizeof(int));//清零操作
    *pret = 10;
    free(pret);
    pret = nullptr;
}

void test2()
{
    /* int(*parr)[10] = new int[10]();
     * //这表明new int[10]()的返回值依然是一个int*型指针变量 */
    int *pInt = new int(10);
    *pInt = 20;
    cout << "*pInt = " << *pInt << endl;
    delete pInt;
    pInt = nullptr;
}
void test3()
{
    int *pInt = new int[10]();
    pInt[0] = 10;
    pInt[1] = 20;
    delete [] pInt;
    pInt = nullptr;
}
int main(int argc, char* argv[])
{
    test();
    return 0;
}

