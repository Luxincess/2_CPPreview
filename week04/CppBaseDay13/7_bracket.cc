#include <iostream>
#include <string.h>
using namespace std;

int arr[10] = {1,3,5,7,9};

class CharArray
{
public:
    CharArray(size_t sz = 10);
    char &operator[](size_t idx);
    char &operator[](size_t idx) const;
    size_t size() const;
    ~CharArray();
private:
    int _size;
    char *_pdata;
};

CharArray::CharArray(size_t sz)
: _size(sz)
, _pdata(new char[_size]())
{
    cout << "CharArray(size_t = 10)" << endl;
}

char &CharArray::operator[](size_t idx)
{
    if(idx < size())
    {
        return _pdata[idx];
    }
    else{
        static char nullchar = '\0';
        return nullchar;
    }
}

char &CharArray::operator[](size_t idx) const
{
    if(idx < size())
    {
        return _pdata[idx];
    }
    else{
        static char nullchar = '\0';
        return nullchar;
    }
}

size_t CharArray::size() const
{
    return _size;
}

CharArray::~CharArray()
{
    cout << "~CharArray()" <<endl;
    if(_pdata)
    {
        delete []_pdata;
        _pdata = nullptr;
    }
}

void test()
{
    const char *pstr = "helloworld";
    CharArray ca(strlen(pstr) + 1);
    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
        ca[idx] = pstr[idx];
    }

    for(size_t idx = 0; idx != ca.size(); ++idx)
    {
        cout << ca[idx] << " ";
    }
    cout << endl;

    const CharArray ca2(10);
    cout << ca2[0] << endl;
}

int main()
{
    test();
    return 0;
}