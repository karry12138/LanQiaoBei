/*
题目描述
根据输入的操作命令，操作队列：1入队、2出队并
输出、了计算队中元素个数并输出。1≤N≤50.
输入描述
第一行一个数字N。接下来 N行，每行第一个数宇
为操作命令：1入队、2出队并输出、3计算队中元
素个数并输出。
输出描述
若干行每行显示一个2 或3命令的输出结果。注意：
2.出队命令可能会出现空队出队（下溢），请输出
“no”，并退出。

输入
7
1 19
1 56
2
3
2
3
2

输出
19
1
56
0
no
*/

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    int n,command,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>command;
        if(command==1)
        {
            cin>>data;
            q.push(data);
        }
        else if(command==2)
        {   
            if(q.empty()) cout<<"no"<<endl;
            else{
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else{
            cout<<q.size()<<endl;
        }
    }


    return 0;
}
//以后用case