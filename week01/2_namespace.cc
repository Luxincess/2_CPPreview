#include <iostream>
using namespace std;

int number = 100;
void print()
{
    cout << "void print()" << endl; 
}

namespace lsx
{
int number = 300;
void print()
{
    cout << "void lsx::print()" << endl;
}

}//end of namespace lsx

int main(int argc, char* argv[])
{
    cout << "number = " << number << endl;
    return 0;
}

