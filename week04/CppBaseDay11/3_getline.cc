#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test()
{
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifstream is not good" << endl;
        return;
    }

    string line;
    while(getline(ifs, line))
    {
        cout << line << endl;
    }
    ifs.close();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

