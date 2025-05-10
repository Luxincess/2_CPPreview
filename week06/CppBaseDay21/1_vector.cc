#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;

void test()
{
    // vector<int> number;
    // vector<int> number(10, 3); //* count 个 value
    int arr[10] = {1,3,5,7,9,2,4,6,8,10};
    vector<int> number(arr, arr+10);  //* 左闭右开的区间
    vector<int> number2 = {1,2,3,4,5,6,7,8,9,10};
    for(size_t idx = 0; idx != number.size(); ++idx)
    {
        cout << number[idx] << " ";
    }
    cout << endl;

    vector<int>::iterator it;
    for(it = number.begin(); it != number.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}

