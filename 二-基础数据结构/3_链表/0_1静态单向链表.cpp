#include <iostream>
using namespace std;

const int N = 10000;

struct node{
    int id;
    int data;
    int nextid;
}nodes[N];

void init()
{
    int n=20; 
    nodes[0].nextid=1;
    for(int i=1;i<=n;i++)
    {
        nodes[i].id = i;
        nodes[i].data = i;
        nodes[i].nextid = i+1; //根据具体需求设置nextid
    }
    nodes[n].nextid = 1; //循环链表
}

//删除节点
void delete_node(int now)
{
    int prev = now - 1;
    nodes[prev].nextid = nodes[now].nextid;
    now = nodes[prev].nextid;
}

int now = 100; //插入节点的索引位置
//向目标节点右方插入节点
void insert(int id,int x)
{
    nodes[now].data = x;
    nodes[now].nextid = nodes[id].nextid;
    nodes[id].nextid = now;
    now++;
}
//遍历链表
void list_print()
{
    int print_cnt = 0;
    for(int i=1;;i=nodes[i].nextid)//不需要设置运行条件，限制条件已经有print_cnt>20了
    {
        cout<<nodes[i].data;
        print_cnt++;
        if (print_cnt>20) break;  //由于表头和表尾相连，会无限输出下去
    }
    cout<<endl;
}


int main()
{
    //初始化
    init();
    cout<<"链表初始化"<<endl;
    list_print();

    //删除节点
    delete_node(2);
    cout<<"删除node[2]节点"<<endl;
    list_print();

    //插入节点
    insert(1,999);
    cout<<"在第一个节点之后插入数据999"<<endl;
    list_print();


    return 0;
}