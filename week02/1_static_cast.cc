#include <stdlib.h>
#include <iostream>
using namespace std;

void test0()
{
    int iNumber = 10;
    float fNumber = 12.34;
    iNumber = (int)fNumber;
    iNumber = int(fNumber);
}

void test()
{
    int iNumber = 10;
    float fNumber = 12.34;
    /* fNumber = (float)iNumber;//c的写法 */
    //用于将一种数据类型转换为另一种数据类型
    fNumber = static_cast<float>(iNumber);//c++的写法

    void *pret = malloc(sizeof(int));
    int *pInt = static_cast<int *>(pret);

}

int main(int argc, char* argv[])
{
    return 0;
}

