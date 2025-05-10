#include <iostream>
#include <string>
using namespace std;

void test()
{
    string s1 = "hello";
    string s2 = "USTC CS";
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;

    cout << endl;
    size_t len1 =s1.size();
    size_t len2 = s2.length();
    cout << "len1 = " << len1 << endl;
    cout << "len2 = " << len2 << endl;

    string s3 = s1 + ',' + s2;
    s3[0] = 'H';
    cout << "s3 = " << s3 << endl;

    cout << endl;
    for(size_t idx = 0; idx != s3.size(); ++idx)
    {
        cout << s3[idx] << " ";
    }
    cout << endl;

    cout << endl;
    const char* pstr = s3.c_str();
    cout << "pstr = " << pstr << endl;


    cout << endl;
    size_t pos = s3.find("USTC");
    string substr = s3.substr(pos);
    cout << "substr = " << substr << endl;

    cout << endl;
    const char* pstr2 = s3.data();
    cout << "pstr2 = " << pstr2 << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

