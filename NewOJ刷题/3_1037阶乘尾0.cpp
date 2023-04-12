/*
题目描述
求N的阶乘末尾存在多少个0。
输入格式
输入存在多组测试数据，对于每组测试数据输入一个整数N(0<=N<=10^9)
输出格式
对于每组测试数据，输出一行表示答案。

输入样例 
12
20
输出样例 
2
4
*/

// #include <iostream>
// using namespace std;

// int main()
// {
//     long long n;
//     int cnt = 0;
//     long long total = 1;
//     while(cin>>n)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             total *= i;
//             if (total%10 == 0)
//             {
//                 total /= 10;
//                 cnt++;
//             }
//         }
//         cout<<cnt<<endl;
//         cnt = 0;
//         total = 1;

//     }
//     return 0;
// }

//8000ms 超时
//原因在于输入规模最大10^9,若是边乘边计数，O(n)顶不住
//只有O(logn)才能顶得住，得对半处理

//第二版
//不能乘。关键在于阶乘计算时，会产生10的就是2，5，10=2*5.
//关键在于有多少个5
//来自网上的理论：n!中有(n/p + n/(p^2) + n/(p^3) + .....)个质因子p
#include<iostream>
using namespace std;
int main()
{
    long long n;
    int ans = 0;
    while(cin>>n)
    {
        while(n)//n<=4时退出
        {
            ans+= n/5;
            n /= 5;
        } 
        cout<<ans<<endl;
        ans = 0;
    }
    return 0;
}