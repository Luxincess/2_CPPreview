#include <iostream>
using namespace std;

void test()
{
    int x, y;
    cin >> x >> y;

    try
    {
        if(0 == y)//编译习惯
        {
            throw y;
        }
        else
        {
            cout << "x/y = " << x/y << endl;
        }
    }
    catch(double e)
    {
        cout << "catch(double)" << endl;
    }
    catch(int e)
    {
        cout << "catch(int)" << endl;
    }
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

