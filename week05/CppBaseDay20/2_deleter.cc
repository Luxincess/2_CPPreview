#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::string;

struct FILECloser
{
    void operator()(FILE *ptr) const
    {
        if(ptr)
        {
            fclose(ptr);
            cout << "fclose(ptr)" << endl;
        }
    }
};

void test()
{
    string msg("hello, world\n");
    unique_ptr<FILE,FILECloser> up(fopen("wd.txt", "a+"));
    fwrite(msg.c_str(), msg.size(), 1, up.get());
    //fclose(up.get());
}

void test2()
{
    FILECloser fc;
    string msg = "hello,world\n";
    //shared_ptr<FILE> sp(fopen("wuhan.txt", "a+"), FILECloser());
    shared_ptr<FILE> sp(fopen("wuhan.txt", "a+"), fc);
    fwrite(msg.c_str(), msg.size(), 1, sp.get());
}

int main()
{
    //test();
    test2();
    return 0;
}

