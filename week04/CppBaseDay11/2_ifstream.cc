#include <string>
#include <fstream>
#include <iostream>
using namespace std;



void test()
{
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifstream is not good" << endl;
        return;
    }
    string word;
    while(ifs >> word)
    {
        cout << word;
    }
    cout << endl;

    ifs.close();
}

void test2()
{
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifs is not good" << endl;
        return;
    }
    string word;
    while(ifs >> word)
    {
        cout << word << endl;
    }
    cout << endl;

    ifs.close();
}

int main(int argc, char* argv[])
{
    test2();
    return 0;
}

