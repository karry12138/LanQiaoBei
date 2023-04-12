//改写自：https://www.jianshu.com/p/1e625af51a3a
// “饱了么”外卖系统中维护着N 家外卖店，编号1~N。 
// 每家外卖店都有一个优先级，初始时(0 时刻) 优先级都为0。 
// 每经过1 个时间单位，如果外卖店没有订单，则优先级会减少1，最低减到0； 
// 而如果外卖店有订单，则优先级不减反加，每有一单优先级加2。 
// 如果某家外卖店某时刻优先级大于5，则会被系统加入优先缓存中； 
// 如果优先级小于等于3，则会被清除出优先缓存。 
// 给定T 时刻以内的M 条订单信息，请你计算T 时刻时有多少外卖店在优先缓存中。

// 第一行包含3 个整数N、M 和T。
// 以下M 行每行包含两个整数ts 和id，表示ts 时刻编号id 的外卖店收到一个订单 
// 1<=N, M, T<=100000，1<=ts<=T，1<=id<=N。

// 输出一个整数代表答案。
#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int order[N];  //order[id]  第id号店上一次的订单
int prior[N];  //prior[id]  第id号店的优先级
int flag[N];   //flag[id]   第id号店在不在优先缓存中
struct node{
    int time,id;
}a[N];
bool cmp(node a, node b){  //结构体排序
    if(a.id==b.id)
        return a.time<b.time;
    return a.id<b.id;
}
int main(){
    int m,n,T;  cin>>n>>m>>T;
    for(int i=0;i<m;i++)
        cin>>a[i].time>>a[i].id;
    sort(a,a+m,cmp);           //按结构体中的时间排序
    for(int i=0;i<m;i++){
        int tt=a[i].time,  id=a[i].id;
        if(tt != order[id])  
              //如果当前订单不等于上一次的订单，则减去它们之间的间隔
            prior[id] -= tt-order[id]-1;
        prior[id] = prior[id] < 0 ? 0: prior[id];  //不小于0
        if(prior[id]<=3)  flag[id]=0;
        prior[id]+=2;
        if(prior[id]> 5)  flag[id]=1;
        order[id]=tt;
    }
    for(int i=1;i<=n;i++)  //最后处理第T时刻
        if(order[i]<T){
            prior[i] -= T-order[i];
            if(prior[i]<=3)
                flag[i]=0;
        }
    int ans=0;
    for(int i=0;i<=n;i++)
        if(flag[i])
            ans++;
    cout<<ans;
    return 0;
}

/*
2 6 6
1 1
5 2
3 1
6 2
2 1
6 2
*/

/*
1
*/