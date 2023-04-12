//起点左上角，碰到矩形边界时左转90度
//输入
//第一行m,n 1<=m,n<=200,表示数字的行与列
//m行n列的数
//输出
//回形取数的顺序，空格隔开，最后一位没有多余空格

#include <iostream>
using namespace std;

int A[201][201]={0};
int visit[201][201]={0}; //该点是否被取过
int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    
    //处理第一个值
    cout<<A[1][1];
    visit[1][1] = 1;

    int cnt = 1; //计数
    int x=1,y=1; //起点
    while(cnt<m*n)//下右上左四个方向
    {
        while(x+1<=m && visit[x+1][y]==0) //查看是否越界或是否被访问过
        {
            cout<<" "<<A[++x][y];
            visit[x][y]=1;
            cnt++;
        }
        while(y+1<=n && visit[x][y+1]==0)
        {
            cout<<" "<<A[x][++y];
            visit[x][y]=1;
            cnt++;
        }
        while(x-1>=1 && visit[x-1][y]==0)
        {
            cout<<" "<<A[--x][y];
            visit[x][y]=1;
            cnt++;
        }
        while(y-1>=1 && visit[x][y-1]==0)
        {
            cout<<" "<<A[x][--y];
            visit[x][y]=1;
            cnt++;
        }
    }
    return 0;
}