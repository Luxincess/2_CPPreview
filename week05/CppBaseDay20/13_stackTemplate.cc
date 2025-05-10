#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;

template <class T = int, size_t sz = 3>
class Stack
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    bool full() const;
    void push(const T &value);
    void pop();
    T top();

private:
    int _top; //栈顶指针
    T *_pdata; //存放元素的底层数组
};

template <class T, size_t sz>
Stack<T, sz>::Stack()
: _top(-1)
, _pdata(new T[sz]())
{

}

template <class T, size_t sz>
Stack<T, sz>::~Stack()
{
    if(_pdata)
    {
        delete [] _pdata;
        _pdata = nullptr;
    }
}

template <class T, size_t sz>
bool Stack<T, sz>::empty() const
{
    return (-1 == _top);
}

template <class T, size_t sz>
bool Stack<T, sz>::full() const
{
    return (_top == sz - 1);
}

template <class T, size_t sz>
void Stack<T, sz>::push(const T &value)  //! push之前一定要记得检查栈是否已满，如果已满就不能入栈
{
    if(!full())
    {
        _pdata[++_top] = value;
    }
    else
    {
        cout << "the stack is full!" << endl;
    }
}

template <class T, size_t sz>
void Stack<T, sz>::pop()             //! pop之前一定要检查栈是否为空，如果为空就不能出栈
{
    if(!empty())
    {
        --_top;
    }
    else
    {
        cout << "the stack is empty!" << endl;
    }
}

template <class T, size_t sz>
T Stack<T, sz>::top()
{
    return _pdata[_top];
}

void test()
{
    Stack<int> st;
    cout << st.empty() << endl;
    cout << st.full() << endl;
    st.push(1);
    cout << st.empty() << endl;
    cout << st.full() << endl;
    st.push(2);
    cout << st.empty() << endl;
    cout << st.full() << endl;
    st.push(3);
    st.push(3);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    // cout << st.empty() << endl;
    // cout << st.full() << endl;
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.empty() << endl;
    // cout << st.full() << endl;
}

void test2()
{
    Stack<string, 13> st;
    st.push("aa");
    for(size_t idx = 1; idx != 15; ++idx)
    {
        st.push(string(2, 'a' + idx));
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    cout << "该栈是不是空的 " << st.empty() << endl;
}

int main()
{
    // test();
    test2();
    return 0;
}

