/*
汉诺塔问题，有ABC三座塔，A塔上有N个圆盘从小到大叠放，圆盘编号从1-N,
现要求把圆盘全部移动到C塔上同样从小到大叠放
在移动圆盘的过程中，一次只能移动一个圆盘，且且只能把小圆盘放在大圆盘上（不允许大盘放在小盘上）

输入2
N:A上有多少个圆盘
M：最少步数下的第M步

输出2
#No: a->b   第M步如何移动编号为No的圆盘，a,b可以是ABC
最少步数
*/
/*思路*/
// 第一步，把前n-1个盘从A塔移动到B塔上
// 第二步，把A塔上最后一个编号为n的盘移动到C塔上
// 第三步，把n-1个盘从B塔移动到C塔上
// 第一步可以递归地看为把n-1个圆盘从A->B的汉诺塔问题
// 第三步可以递归地看为把n-1个圆盘从B->C的汉诺塔问题

#include <iostream>
using namespace std;

const int N=10000;
int sum=0,m;
struct mystack
{
    int a[N];
    int t=-1;
    void push(int x) { a[++t]=x; }
    int top() { return a[t]; }
    void pop() { t--; }
}s[4]; //使用s[1]-s[3]

void init_s1(int n)
{
    for(int i=n;i>=1;i--)
        s[1].push(i);
}

void move(int from, int to)
{
    int No = s[from].top();
    s[from].pop();
    s[to].push(No);
    sum++;

    char a,b;
    if(from==1) a='A';
    if(from==2) a='B';
    if(from==3) a='C';
    if(to==1) b='A';
    if(to==2) b='B';
    if(to==3) b='C';

    if(sum==m) cout<<"#"<<No<<": "<<a<<"->"<<b<<endl; 
    // cout<<"#"<<No<<": "<<a<<"->"<<b<<endl;
    
}
void hanoi(int from,int temp, int to, int n)
{
    if(n==1){
        move(from,to);
    }
    else{
        hanoi(from,to,temp,n-1); //第一步递归
        move(from,to);
        hanoi(temp,from,to,n-1); //第三部递归
    }
}

int main()
{
    int n;
    cin>>n>>m;
    init_s1(n);
    hanoi(1,2,3,n);
    cout<<sum<<endl;
    return 0;
}