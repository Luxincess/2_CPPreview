#include <iostream>

int cout(int x, int y)
{
    std::cout << "x = " << x << ", y = " << y << std::endl;
}


int main(int argc, char* argv[])
{
    int a = 3, b = 4;
    cout(a, b);
    return 0;
}

