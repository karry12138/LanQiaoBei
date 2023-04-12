/*输入2
N:A上有多少个圆盘
M：最少步数下的第M步

输出2
#No: a->b   第M步如何移动编号为No的圆盘，a,b可以是ABC
最少步数
*/

// 思路：
// 简单尝试
// N=1, 1:1A->C
// N=2, 1:1A->B 2:2A->C 3:1B->C
// N=3, 1:1A->B 2:2A->B 3:3A->C 4:2B->C 5:1B->C

// n=1时，直接出栈到C
// n>=2时，前n-1个圆盘从A出栈，入栈至B;  第n个圆盘A->C; 然后B上n-1个圆盘出栈，入栈至C
//!!!!!!!!错误，大盘不能叠放在小盘上，所以不能把前n-1个盘倒过来叠放在B

#include<iostream>
using namespace std;

const int N = 10000;
struct stack
{
	int A[N];
	int t=-1;
	void push(int x) { A[++t]=x;}
	int top() { return A[t]; }
	void pop() { t--; }
	int empty() { return (t==-1)?1:0 ;}
}a,b,c;

void init_a(int n)
{
	for(int i=n;i>=1;i--)
		a.push(n);
}

int main()
{
	int n,m;
    int cnt=0;
	cin>>n>>m;
    init_a(n);
    if(m==1) 
    {
        cout<<"#1: A->C"<<endl;
        cout<<1<<endl;
    }
    else{
        for(int i=1;i<=n-1;i++)
        {
            cnt++;
            b.push(a.top());
            a.pop();
            if(cnt==m) cout<<"#"<<m<<": A->B"<<endl;
        }
        cnt++;
        if(cnt==m){
            cout<<"#"<<m<<": A->C"<<endl;
            c.push(a.top());
            a.pop();
        }

        for(int i=n-1;i>=1;i++)
        {
            cnt++;
            c.push(a.top());
            b.pop();
            if(cnt==m) cout<<"#"<<m<<": B->C"<<endl;
        }
    }
    cout<<cnt<<endl;

	
	return 0;
}