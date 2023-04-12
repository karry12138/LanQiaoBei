/*
题目描述
有几辆自行车依次来到停车棚，除了第一辆自行车
外，
，每辆自行车都会怡好停放在已经在停车棚里的某
辆自行车的左边或右边。(e.g.停车棚里已经有了辆自
行车，从左到右编号为：3,5,1。现在编号为2的第
4辆自行车要停在 5号自行车的左边，所以现在停车
棚里的自行车编号是：3,2,5,1)。给定n辆自行车的
停放情况，按顺序输出最后停车棚里的自行车编号。
n< 100000。
输入描述
第一行一个整数几。第二行一个整数x。表示第一辆
自行车的编号，
以下n-1行，每行3个整数
x,y,z。z=0时，表示编号为x的自行车恰停放
在编号为y的自行车的左边。z=1时，表示编号
为x的自行车恰停放在编号为y的自行车的右边。
输出描述
从左到右输出停车棚里的自行车编号
*/

/*
样例输入
4
3
1 3 1
2 1 0
5 2 1
样例输出
3 2 5 1
*/

//使用双向链表
#include<iostream>
using namespace std;

const int N = 100000+2;
struct node{
    int data;//车的编号
    int preid;
    int nextid;
}nodes[N]; //实际使用时，通过preid与nextid链接的链表的索引并不连续

int now = 0;
int location[N] = {0};//方便定位 车的编号为x在nodes[now]处 location[x] = now
void init_nodes()
{
    nodes[0].nextid=1; //nextid为1的，只会是倒数第二个节点
    nodes[1].preid=0; //nodes[1]就是最后一个节点。一切节点都塞在nodes[0]与nodes[1]之间
                    //nodes[0]与nodes[1]作为起点与终点，本身不存放任何数据
    now = 2; //nodes[now]从nodes[2]开始
}

void insert(int k,int x)//将新节点插在已有索引为k的节点的右边
//k为索引/id，x为编号
{
    nodes[now].data = x;//存入数据到now节点
    location[x] = now;
    //双向链表插入节点，要处理四步
    nodes[now].nextid = nodes[k].nextid; //now接前后
    nodes[now].preid = k;
    nodes[nodes[k].nextid].preid = now; //前后接now
    nodes[k].nextid = now;
    now++;
}

int main()
{
    int n; cin>>n;
    init_nodes();
    int a; cin>>a;
    insert(0,a);//插入第一辆车,在nodes[0]右边
    n--;
    while(n--)
    {
        int x,y,z; //y为已有编号，x为新编号
        cin>>x>>y>>z;
        if (z==0) insert(nodes[location[y]].preid,x);//x插在y左边
        if (z==1) insert(location[y],x);//x插在y右边
    }

    for(int i=nodes[0].nextid;i!=1;i=nodes[i].nextid)
        cout<<nodes[i].data<<" ";
    return 0;
}