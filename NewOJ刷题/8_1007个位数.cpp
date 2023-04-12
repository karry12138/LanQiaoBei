//对于输入的所有整数，指出其个位数
//思路为读成string，并输出string[s.size()-1]

//追注：简简单单%10就行
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;
    while(cin>>a)
    {
        cout<<a[a.size()-1]<<endl;
    }
    return 0;
}