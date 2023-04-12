#include<iostream>
using namespace std;

//最简单的链队列-会溢出
// int main()
// {   
//    // cout<<1<<endl;
//     const int MAX = 1e5;
//     int que[MAX]={0};
//     int head=0,tail=0;

//     head++;// 弹出队头

//     int data=999;
//     que[++tail] = data; //数据入队

//     // cout<<1<<endl;

//     cout<<que[head]<<endl;//读取数据
//     head++;

//     return 0;
// }




//循环队列
const int N=10003;
struct queue
{
    int data[N]={0};
    int head=0,rear=0;
    int size()//返回队列长度
    {
        return (rear - head + N)%N;
    }
    bool empty()//队列判空
    {
        if(size()==0) return true;
        else return false;
    }
    bool push(int x)//队尾插入新元素，rear指向下一个空位
    {
        if((rear+1)%N==head) return false; //队列满
        data[rear] = x;
        rear = (rear+1)%N;  //循环队列,rear达到N时重置为0
        return true;
    }
    bool pop(int &e)//返回队头元素给传入的参数，并将其删除
    {               //*****好神奇，第一次见这种用法
        if (head==rear) return false; //队列空
        e = data[head];
        head = (head+1)%N;
        return true;
    }
    int front()//返回队头但不删除
    {
        return data[head];
    }
};

int main()
{
    struct queue q1;
    q1.push(1);
    cout<<q1.front()<<endl;
    int a;
    q1.pop(a);
    cout<<a<<endl;
    cout<<q1.size()<<endl;
    
    

    return 0;
}