#include <iostream>
using namespace std;

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
    cout << "lsx::number = " << lsx::number << endl;
    lsx::print();
    return 0;
}

