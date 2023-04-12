#include<iostream>
using namespace std;
const int M = 251;               //定义最大金额
const int N = 5;                 //5种硬币
int type[N] = {1,5,10,25,50};    //5种面值
int cnt[M];                      //每个金额对应最少的硬币数量
int path[M]={0};                 //记录最小硬币的路径
// const int INF = 0x1FFFFFFF;
const int INF = INT_MAX;
void solve(){
    for(int k=0; k< M;k++)
        cnt[k] = INF;    //全部赋最大值
        cnt[0]=0;
    for(int j = 0;j < N;j++)
        for(int i = type[j]; i < M; i++)
            if(cnt[i] >  cnt[i - type[j]]+1){
               path[i] = type[j];   //在每个金额上记录路径，即某个硬币的面值
               cnt[i] = cnt[i - type[j]] + 1;  //递推式
            }
}
void print_ans(int *path, int s) {      //打印硬币组合
    while(path[s]!=0 && s>0){
        cout << path[s] << " ";
        s = s - path[s];
    }
}
int main() {
    int s;
    solve();
    while(cin >> s){
        if(cnt[s] == INF)
            cout <<"No answer"<<endl;
        else{
            cout << cnt[s] << endl;     //输出最少硬币个数
            print_ans(path,s);             //打印硬币组合
        }
    }
    return 0;
}