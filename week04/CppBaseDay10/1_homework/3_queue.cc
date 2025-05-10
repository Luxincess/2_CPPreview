#include <iostream>
using namespace std;

class Queue
{
public:
    Queue(int size = 10);
    bool full() const;
    bool empty() const;
    void push(const int &value);
    void pop();
    int front();
    int back();
    ~Queue();
private:
    int _size;
    int _front;
    int _rear;
    int *_data;
};

Queue::Queue(int size)
: _size(size)
, _front(0)
, _rear(0)
, _data(new int[_size]())
{
    cout << "Queue(int)" << endl;
}

bool Queue::full() const
{
    if((_rear - _front + _size)%_size == _size - 1)
        return true;
    else return false;
}

bool Queue::empty() const
{
    if(_front == _rear)
        return true;
    else return false;
}

void Queue::push(const int &value)
{
    if(!full())
    {
        _data[_rear] = value;
        _rear = (_rear + 1) % _size;
    }
    else 
    {
        cout << "Queue is full" << endl;
    }
}

void Queue::pop()
{
    if(!empty())
    {
       /* cout << _data[_front] << endl; */
       _front = (_front + 1) % _size;
    }
    else
    {
        cout << "Queue is empty" << endl;
    }
}

int Queue::front()
{
    if(!empty())
    {
        return _data[_front];
    }
    else
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
}

int Queue::back()
{
    if(!empty())
    {
        return _data[(_rear - 1) % _size];
    }
    else
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
}

Queue::~Queue()
{
    cout << "~Queue()" << endl;
    if(_data)
    {
        delete []_data;
        _data = nullptr;
    }
}

void test()
{
    Queue q;
    cout << "Queue is empty?" << q.empty() << endl;
    q.push(1);
    cout << "Queue is full?" << q.full() << endl;
    
    for(int idx = 2; idx != 15; ++idx)
    {
        q.push(idx);
    }

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << "Queue is empty?" << q.empty() << endl;
}

int main(int argc, char* argv[])
{
    test();
    return 0;
}

