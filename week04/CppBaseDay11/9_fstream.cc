#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void test()
{
    string fileName("wuhan.txt");
    fstream fs(fileName);
    if(!fs.good())
    {
        cerr << "fstream is not good" << endl;
        return;
    }

    int number = 0;
    for(size_t idx = 0; idx < 5; ++idx)
    {
        cin >> number;
        fs << number << " ";
    }

    size_t pos = fs.tellg();
    cout << "pos = " << pos << endl;
    fs.seekp(-pos, std::ios::end);
    for(size_t idx = 0; idx < 5; ++idx)
    {
        fs >> number;
        cout << number << " ";
    }

    fs.close();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

