#include <iostream>
using namespace std;
const long N=100002;
long location[N] ={0};  //用编号
struct nodes
{
  long id;
  long preid;
  long nextid;
}list[N]; //把输入的车依次塞进list

int now = 0; //通过now与now++代表第几个塞入list的车

void init()
{
  list[0].nextid = list[1].id; //list[0]为起点，list[1]为终点
  list[1].preid = list[0].id; //一切新节点都将插入0与1之间。分配的节点从list[2]起
  now = 2;
}

void insert(long now, long new_) //在索引k右侧插入
{
  nodes node_now = list[location[now]];
  list[location[[node_now.preid]]].nextid = new_;
  new_

}

int main()
{
  long n,a;
  cin>>n>>a;
  location[a] = now;

}
