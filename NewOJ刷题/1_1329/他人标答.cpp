#include<iostream>
#include<string.h>
using namespace std;
int sett[100002];
long gcc[100002];
int main()
{
    int n,k;
    cin>>n>>k;
    long count=0;
    long sum=0;
    memset(gcc,0,sizeof(gcc));
    for(int i=0;i<n;i++)
    {
        cin>>sett[i];
        sum+=sett[i];//记录前缀和
        gcc[ sum%k ]++;//余数为k的区间加一
    }
    //余数相同的区间相减可以构成一个k倍区间
    count = gcc[0];
    for(int i=0;i<k;i++)
    {
        count+=gcc[i]*(gcc[i]-1)/2;
    }    
    cout<<count<<endl;
    return 0;
}