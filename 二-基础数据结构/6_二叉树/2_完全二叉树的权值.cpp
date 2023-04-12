// 完全二叉树
/*
给定一个含N个节点的完全二叉树
从上到下从左到右给每个节点一个权值A_i(共n个)
对同一深度的节点权值进行求和，输出权值之和最大的深度(和相同深度小者优先)
第一层深度为1
*/
/*
输入
第一行 N [1,10^5]
第二行 A_1 ~ A_n  N个数，[1,10^5]
输出 
权值之和最大的深度 (相同时深度小者优先)
*/
/*
样例输入
7
1 6 5 4 3 2 1
样例输出
2
*/
#include<iostream>
#include<cmath>
using namespace std;
const int N =10000+1;
// int tree[N];
long node_power;
int depth_sum[20];  //存储深度的权值之和

int max_index(int a[],int size) //返回值最大的深度
{
    int index = 1;
    int max = a[index];
    for(int i=1;i<=size;i++)
        if(a[i]>max){
            index = i;
            max = a[i];
        }
    return index;
}
int main()
{
    long n;
    cin>>n;
    int max_depth = ceil(log(n+1)/log(2));  //求完全二叉树总共有几层
    for(long i=1;i<=n;i++)
    {
        // cin>>tree[i];
        cin>>node_power;
        int level = ceil(log(i+1)/log(2));  //获取该节点位于第几层
        depth_sum[level] += node_power;     //该层权值累加
    }
    // for(int i=1;i<=max_depth;i++)
    //     cout<<depth_sum[i]<<endl;
    cout<<max_index(depth_sum,max_depth);
    return 0;
}