#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
public:
    SafeFile(FILE *fp)
    : _fp(fp)
    {
        cout << "SafeFile(FILE * )" << endl;
        if(nullptr == _fp)
        {
            cout << "nullptr == _fp" << endl;
        }
    }

    void wirte(const string &msg)
    {
        fwrite(msg.c_str(), msg.size(), 1, _fp);
    }

    ~SafeFile()
    {
        cout << "~SafeFile()" << endl;
        if(_fp)
        {
            fclose(_fp);
            cout << "fclose(_fp)" << endl;
        }
    }
private:
    FILE *_fp;
};


void test()
{
    string msg  = "hello,world\n";
    SafeFile sf(fopen("wd.txt", "a+"));
    sf.wirte(msg);
}

int main()
{
    test();
    return 0;
}

