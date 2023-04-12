#include <iostream>
#include <list>
using namespace std;

//全局变量定义
long i, n;
list<int>L;
list<int>::iterator location[100000+3]; //用编号(值)找迭代器


int main()
{
    //初始化部分
    int data;
    cin>>n>>data;
    L.push_back(data);
    location[data] = L.begin();
    
    list<int>::iterator temp;
    for(i=1;i<=n-1;i++)
    {   
        int x,y,z;
        cin>>x>>y>>z;
        temp = location[y];
        if(z==0)
        {
            L.insert(temp,x);
            location[x] = --temp;//记录插入x的迭代器位置
        }
        else
        {
            L.insert(++temp,x);
            location[x] = --temp;
        }
    }
    list<int>::iterator it;
    //输出部分
    for(it = L.begin();it!=L.end();it++)
        cout<<*it<<" ";
    return 0;
}