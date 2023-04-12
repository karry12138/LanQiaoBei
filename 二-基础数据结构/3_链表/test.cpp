#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> L;
    for(int i=2;i<=8;i++)
        L.push_back(i+10);
    list<int>::iterator it=L.begin();
    for(;it!=L.end();it++)
        cout<<*it<<"-"<<endl;
    for(int i=1;i<=10;i++)
    {   
        cout<<*it<<endl;
        it++;
    }
    it = --L.begin();
    cout<<"*it:"<<*it<<endl;
    // it++;
    // cout<<*it<<endl;
    // it++;
    // cout<<*it<<endl;
    it = L.end();
    cout<<"*it:"<<*it<<endl;
    cout<<"L.size()"<<L.size()<<endl;
    return 0;
}