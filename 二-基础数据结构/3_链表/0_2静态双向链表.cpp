#include <iostream>
using namespace std;

const int N = 10000;
struct node{
    int id;
    int data;
    int preid;
    int nextid;
}nodes[N];

//链表初始化
void init()
{
    int n=10;

    nodes[0].nextid=1;
    nodes[1].preid =0;
    for(int i=1;i<=n;i++)
    {
        nodes[i].id = i;
        nodes[i].data = i;
        nodes[i].preid = i-1;
        nodes[i].nextid = i+1;
    }
    
    nodes[n].nextid=1;
    nodes[1].preid = n;//循环链表
}

//删除节点
void delete_node(int now)
{   
    int prev = nodes[now].preid;
    int next = nodes[now].nextid;
    nodes[prev].nextid=nodes[now].nextid;
    nodes[next].preid = nodes[now].preid;
    now = next;
}

int now = 100;
//向目标节点右方插入节点
void insert(int id,int x)
{
    nodes[now].data = x;
    nodes[now].nextid = nodes[id].nextid;
    nodes[now].preid = id;
    nodes[nodes[id].nextid].preid = now;
    nodes[id].nextid = now;
    now++;
}


//向前遍历
void print_forward()
{
    int print_cnt = 0;
    for(int i=1; ;i=nodes[i].nextid)
    {
        cout<<nodes[i].data;
        print_cnt++;
        if (print_cnt>=20) break;
    }
    cout<<endl;
}

//向后遍历
void print_backward()
{
    int print_cnt = 0;
    for(int i=10; ;i=nodes[i].preid)
    {
        cout<<nodes[i].data;
        print_cnt++;
        if (print_cnt>=20) break;
    }
    cout<<endl;
}
int main()
{
    init();
    //遍历链表
    cout<<"初始化后向前、向后遍历节点"<<endl;
    print_forward();
    print_backward();
    //删除节点
    cout<<"删除nodes[2]节点"<<endl;
    delete_node(2);
    print_forward();

    //插入节点
    insert(5,999);
    cout<<"在nodes[5]的节点后插入另一个值为999的节点"<<endl;
    print_forward();

    return 0;
}