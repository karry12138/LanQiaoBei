// 字符串操作
// 题目描述
// 编写一个程序，判定字符串t是否是字符串s的子串。
// 输入格式
// 两个字符串，各占一行，长度不超过100。 
// 第一行是字符串s，第二行是字符串t 
// 输出格式
// 输出子串所在的下标，下标从0开始计数。如未找到输出-1
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    int result = s.find(t);
    cout<<result;
    return 0;
}
/*
aababcabcdabcde
abcd
*/
/*
6
*/