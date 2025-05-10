#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void test()
{
    vector<string> vec_str;
    ifstream ifs("wd.txt");
    if(!ifs.good())
    {
        cerr << "ifstream is not good" << endl;
        return;
    }
    string line;
    while(getline(ifs, line))
    {
        vec_str.push_back(line);
    }
    for(auto it = vec_str.begin(); it != vec_str.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << vec_str[9] << endl;
    cout << vec_str[36] << endl;

    ifs.close();
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

