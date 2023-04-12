/*给定一个长度为N的数列，A1, A2, ... AN。 
如果其中一段连续的子序列Ai, Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。   
你能求出数列中总共有多少个K倍区间吗？  */

//想法
/*
给求出所有连续字数列之和，然后判断是否能倍K整除
*/

/*
#include <iostream>
using namespace std;
// const long n=100000+1;
const long n=100000+1;
// const int n=10000+1;
int a[n] ={0};


int main() {
    long N,K;
    int count=0;
    cin>>N; cin>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=N;i++) //起点
    {
        for(int j=1;j<=N;j++)//长度
        {    
            if(i+j-1>N) continue;
            long sum = 0;
            for(int k=0;k<j;k++)//累加
            {
                sum = sum + a[i+k];
            }
            if(sum%K==0) count++;
        }
    }
    cout<<count;
    return 0;
}

//第一次n=10 0000超时
//第二次n=10000越界

*/

/*
看了一些题解之后发现：
1.用前缀和
2.余数相等的前缀和一减，可以得到k倍区间
余数相等的前缀和达到2个时，新增一个k倍区间
达到3个时，新增2个
达到4个时，新增3个

其实n个余数相等的前缀和，任选两个相减就可以得到一个k倍区间
nC2
*/

//这是我的新答案
#include <iostream>
using namespace std;
const long n=100000+1;
long sum[n] = {0}; //前缀和
long remain_count[n] = {0};  //余数计数
// int ans = 0;  //竟然还有答案大于32676的情况，不过也是，组合数很容易大
long ans = 0;


int main() {
    long N,K;
    cin>>N>>K;

    //录入前缀和，从1起
    for(long i=1;i<=N;i++)
    {
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }

    for(long i=1;i<=N;i++)
    {
        remain_count[sum[i]%K]++;
        ans += remain_count[sum[i]%K] - 1; //新增的同余前缀和与已有的所有前缀和各减一次，可以得到数量为已有前缀和的k倍区间
        if(sum[i]%K == 0) ans++; //考虑其本身余数为0，已经是k倍区间的情况
    }

    cout<<ans;
    return 0;
}