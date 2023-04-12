// 题目描述
// 稀疏数组就是数组中大部分内容都没有被使用（或都为0），在数组中仅有少部分空间使用，导致内存空间的浪费。 
// 为了节省空间，现在将下列稀疏数组进行压缩。 
// 数组为n行m列，存在一大部分是0表示该位置未被使用，非0则表示已经使用。 
// 将所有非0元素按照（行下标、列下标、元素值）存储下来，完成稀疏数组的压缩。 

// 输入格式
// 第一行为两个整数n,m(1<=n,m<=50) 
// 接下来n行，每行m个元素表示稀疏数组。 

// 输出格式
// 输出第一行先输出n,m,x。x表示非0元素数目 。接下来x行，每行输出行下标、列下标、元素值。 
// 按照行下标从小到大的顺序输出，如果同一行按照列下标从小到大的顺序输出。
#include <iostream>
using namespace std;
// int A[50][50]={0}; //不需要
int cnt=0;
struct node{
    int x,y,z;
}used[2500];
int main() 
{
    int n,m,value;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>value;
            if(value!=0){
                used[cnt].x=i;
                used[cnt].y=j;
                used[cnt].z=value;
                cnt++;
            }
        }
    cout<<n<<" "<<m<<" "<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cout<<used[i].x<<" ";
        cout<<used[i].y<<" ";
        cout<<used[i].z<<" "<<endl;
    }
    return 0;
}
/*
3 3
1 0 0
8 0 9
0 0 5
*/
/*
3 3 4
0 0 1
1 0 8
1 2 9
2 2 5
*/