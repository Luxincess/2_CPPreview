#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test()
{
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifstream sis not good" << endl;
        return;
    }
    string line[100];
    size_t idx = 0;
    while(getline(ifs, line[idx]))
    {
        cout << line[idx] << endl;
        ++idx;
    }

    cout << "line[9] = " << line[9] << endl;
    cout << "line[36] = " << line[36] << endl;
    ifs.close();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

