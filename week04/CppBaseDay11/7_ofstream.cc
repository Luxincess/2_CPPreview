#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void test()
{
    ofstream ofs("test.txt");
    if(!ofs.good())
    {
        cerr << "ofstream is not good" << endl;
        return;
    }
    ofs << "wangdao" << endl;
    ofs.close();
}

void test2()
{
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifstream is not good" << endl;
        return;
    }

    ofstream ofs("test.txt");
    if(!ofs.good())
    {
        cerr << "ofstream is not good" << endl;
        return;
    }
    string line;
    while(getline(ifs, line))
    {
        ofs << line << endl;
    }
    ifs.close();
    ofs.close();
}

int main(int argc, char* argv[])
{
    test2();
    return 0;
}

