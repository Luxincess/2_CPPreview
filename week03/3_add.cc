#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

int add(int x, int y)
{
    return x + y;
}

#ifdef __cplusplus
}//end of extern "C"
#endif

float add(float x, float y)
{
    return x + y;
}

long add(long x, long y)
{
    return x + y;
}

int add(int x, float y)
{
    return x + y;
}

int add(float x, int y)
{
    return x + y;
}
int add(int x, int y, int z)
{
    return x + y + z;
}
void test()
{
    int *pInt = static_cast<int *>(malloc(sizeof(int)));
    memset(pInt, 0, sizeof(int));
    free(pInt);
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

