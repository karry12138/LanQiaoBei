#include<iostream>
#include<cmath>
using namespace std;
int cnt=0;  

int main()
{
    int n=2022;
    int max_depth = ceil(log(n+1)/log(2));  //求完全二叉树总共有几层
    for(int i=1;i<=n;i++)
    {
        int level = ceil(log(i+1)/log(2));  //获取该节点位于第几层
        if(level==max_depth) cnt++;     //若在最后一层，计数
    }
    cout<<cnt;
    return 0;
}