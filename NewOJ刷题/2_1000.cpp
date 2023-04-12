//给多组数据，算a+b
//关键在于自动读完所有数据
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
        cout<<a+b<<endl;
    return 0;
}