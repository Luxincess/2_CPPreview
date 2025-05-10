#include <set>
#include <iostream>
#include <utility>
#include <string>
using namespace std;

void test()
{
    set<int> number = {1,3,3,7,9,5,7,9};
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << endl;
    size_t cnt = number.count(5);
    cout << "cnt = " << cnt << endl;
    set<int>::iterator it = number.find(17);
    if(it == number.end())
    {
        cout << "not in set" << endl;
    }
    else
    {
        cout << "in set " << *it << endl;
    }

    cout << endl;
    pair<set<int>::iterator, bool> ret = number.insert(8); 
    if(ret.second)
    {
        cout << "插入成功: " << *ret.first << endl;
    }
    else
    {
        cout << "插入失败,因为该元素已经在set中" << endl;
    }

    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    cout << endl;
    auto it2 = number.begin();
    cout << "it2 = " << *it2 << endl;

}

void test2()
{
    pair<int,string> number = {1, "hello"};
    cout << number.first << "  " << number.second << endl;
}

int main()
{
    test2();
    return 0;
}

