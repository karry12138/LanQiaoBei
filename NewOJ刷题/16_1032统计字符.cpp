/*
题目描述
给出一个字符串，统计其中的英文字母、空格、数字的个数。
输入格式
输入一行，为给定字符串
*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string a;
    int letter=0,space=0,digit=0;
    getline(cin,a);
    for(int i=0;i<a.length();i++)
    {
        if((a[i]>='a' && a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
            letter++;
        if(a[i]==' ')
            space++;
        if(a[i]>='1' && a[i]<='9')
            digit++;
    }
    cout<<"letter="<<letter<<endl;
    cout<<"space="<<space<<endl;
    cout<<"digit="<<digit<<endl;
    return 0;
}


/*
aaaaaa 11111 2223www
*/
/*
letter=9
space=2
digit=9
*/