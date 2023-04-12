#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(100);
    q.push(200);
    cout<<q.front()<<endl; //返回队首
    cout<<q.back()<<endl; //返回队尾
    cout<<q.size()<<endl; //返回队列大小
    cout<<"is_empty:"<<q.empty()<<endl; //队列大小是否为0
    q.pop();//删除队首
    q.pop();
    cout<<"is_empty:"<<q.empty()<<endl;
    return 0;
}