//先对数据做排序，方便后面统计处理

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000+1;

struct node{
    long id,time;
}a[N];

bool compare(node a, node b)
{
    if(a.id == b.id){
        return a.time<b.time;
    }
    return a.id<b.id;
}

