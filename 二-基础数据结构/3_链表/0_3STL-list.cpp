#include <iostream>
#include <list>
using namespace std;

list<int>nodes;

void init()
{

    int n=10;
    for(int i=0;i<=n;i++)
    {
        nodes.push_back(i+100);//往容器尾部塞入一个值
    }
}
//遍历
void print_list()
{
    list<int>::iterator it = nodes.begin();
    int print_cnt=0;
    while(nodes.size()>1)
        {
            cout<<*it;
            it++;
            print_cnt++;
            if(it == nodes.end()) it=nodes.begin(); //循环定义
            if(print_cnt>=20) break;
        }
    cout<<endl;
}

//插入。需要迭代器定位，默认向目标位左侧插
void insert_nodes(list<int>::iterator it,int data,int left_or_right=0)
{
    list<int>::iterator temp = it;//避免对原值修改
    if(left_or_right==0) nodes.insert(temp,data);
    else nodes.insert(++temp,data);
}

int main()
{
    init();
    print_list();

    //删除节点,需要迭代器定位

    /*---------关于容器的边界问题-----------*/
    //容器中存放着push进去的n个数据，第一个数据对应begin(),第n个数据对应end()--
    //在最后另外有一个位置存放容器的size，对应end()
    //而end()++则回到begin()

    // it = ++nodes.begin();//删除第二个节点
    list<int>::iterator it = --nodes.end();//设置要删去的节点。此it为最后一个数据节点
    list<int>::iterator next= ++it;  //next与it等价。此外两者此时都对应end()
    if(next == nodes.end()) next=nodes.begin(); //若next指向end()，重新定义next为begin()
    nodes.erase(--it); //之前++过，所以此处--才是实际要删去的节点
    // it = next;

    cout<<"\n删去最后一个结点110后"<<endl;
    print_list();

    it = nodes.end();
    cout<<"在末尾位置左插999"<<endl;
    insert_nodes(it,999);
    print_list();
    cout<<"在末尾位置左插888"<<endl;
    insert_nodes(it,888);
    print_list();
    return 0;
}