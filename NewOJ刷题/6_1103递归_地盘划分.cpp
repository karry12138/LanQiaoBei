/* 递归 */
/*
对于一个n*m的矩形，最少可以划分成多少个正方形。
输入存在多组测试数据，每组测试数据输入两个正整数n,m，n,m不超过10^9。
对于每组测试数据输出一行表示答案
输入样例 
3 4
2 2
输出样例 
4
1
*/

#include <iostream>
using namespace std;
typedef long long ll;
ll n,m;
int cnt=0;

void solve(ll n, ll m)
{
    if(n<=m) swap(n,m); //确保n最大
    if(n%m==0) cnt+=(n/m);
    else{
        ll square = n/m;  //大小为m*m的正方形
        cnt+=square;
        n-=square*m;
        solve(n,m);
    }
}

int main()
{
    while(cin>>n>>m){
        solve(n,m);
        cout<<cnt<<endl;
        cnt = 0;
    }
    return 0;
}