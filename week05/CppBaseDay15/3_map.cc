#include <iostream>
#include <utility>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;
using std::make_pair;

void test()
{
    map<int,string> number = {
        pair<int,string>(1,"hello"),
        pair<int,string>(2,"world"),
        pair<int,string>(2,"world"),
        {6,"wuhan"},
        {7,"beijing"},
        make_pair(4, "hello"),
        make_pair(10, "world"),
        make_pair(6, "world"),
    };

    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;
    size_t cnt = number.count(6);
    cout << "cnt = " << cnt << endl;
    map<int, string>::iterator it = number.find(7);
    if(it == number.end())
    {
        cout << "该元素不在map中" << endl;
    }
    else
    {
        cout << "该元素存在map中 "
             << it->first <<" "
             << it->second << endl;
    }

    cout << endl;
    pair<map<int,string>::iterator,bool> ret =
    number.insert(pair<int,string>(3,"lsx"));
    if(ret.second)
    {
        cout << "插入成功 " << ret.first->first
             << " " << ret.first->second << endl;
    }
    else
    {
        cout << "插入失败，该元素存在map中 " << endl;
    }

    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << endl << endl;
    //存在就是查找，不存在就是插入
    cout << "number[1] = " << number[1] << endl;
    cout << "number[5] = " << number[5] << endl;
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    cout << endl;
    number[5] = "beijing";
    number[1] = "beijing";
    for(auto it = number.begin(); it != number.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    test();
    return 0;
}

