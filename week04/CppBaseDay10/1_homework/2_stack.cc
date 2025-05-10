#include <iostream>
using namespace std;

class Stack
{
public:
    Stack(size_t size = 10);
    ~Stack();
    bool empty() const;
    bool full() const;
    void push(const int &value);
    void pop();
    int top();
private:
    int _top;
    size_t _size;
    int *_pdata;
};

Stack::Stack(size_t size)
: _top(-1)
, _size(size)
, _pdata(new int[_size]())
{
    cout << "Stack(size_t = 10)" << endl;
}

Stack::~Stack()
{
    cout << "~Stack()" << endl;
    if(_pdata)
    {
        delete []_pdata;
        _pdata = nullptr;
    }
}

bool Stack::empty() const
{
    if(_top == -1)
    {
        return true;
    }
    return false;
}

bool Stack::full() const
{
    if(_top == (int)(_size - 1))
    {
       return true; 
    }
    return false;
}

void Stack::push(const int &value)
{
    if(!full())
    {
        _top++;
        _pdata[_top] = value;
    }
    else
    {
        cout << "stack is full" << endl;
    }
}

void Stack::pop()
{
    if(!empty())
    {
        _top--;
    }
    else 
    {
        cout << "stack is empty" << endl;
    }
}

int Stack::top()
{
    if(!empty())
    {
        return _pdata[_top];
    }
    else
    {
        cout << "stack is empty" << endl;
        return -1;
    }
}

void test()
{
    Stack st(10);
    cout << "stack is empty?" <<st.empty() << endl;
    st.push(1);
    cout << "stack is full?" << st.full() << endl;

    cout << endl;
    for(size_t idx = 2; idx != 13; ++idx)
    {
        st.push(idx);
    }

    cout << "stack is full?" << st.full() << endl;

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

