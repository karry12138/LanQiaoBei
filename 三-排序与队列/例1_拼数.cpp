/*
对输入的n个整数，进行拼接，使拼得的数最大
input:
n  表示将输入的数字个数  [1,20]
numbers  [1,10^9]
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool my_greater(string a, string b)
{
    return a+b>b+a;
}
int main()
{
    int n;
    cin>>n;
    string array[20];
    for(int i=0;i<n;i++)
        cin>>array[i];
    sort(array,array+n,my_greater);  //可迭代器的首地址，末地址，可选：排序规则默认升序，可自定义
    for(int i=0;i<n;i++)
        cout<<array[i];
    return 0;
}
/*
3
13 312 343
*/
/*
34331213
*/