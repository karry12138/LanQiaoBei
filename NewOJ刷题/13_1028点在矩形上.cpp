// 在平面直角坐标系中有一矩形左下角坐标是（a，b），右上角坐标是（c，d），矩形的边平行于坐标轴。 
// 现在有一系列点（xi，yi），i=0，...，n-1，请你判断它们与矩形的位置关系，分为在矩形内、在矩形上或在矩形外。 

// 输入有多组测试数据 
// 每组测试数据第一行是一个整数n，第二行是矩形的左下角和右上角的坐标，接下来n行是要判断的点。 
// 输入坐标均为整数点，数字范围在[-1000,1000]之间 

// 如果点在平面内或上就输出YES，否则输出NO，每个测试数据以空行区分。
#include<iostream>
using namespace std;
int n,a,b,c,d;
// 发现多余了
// bool on_rectangle(int x,int y)
// {
//     if(((x=a || x=c) && (y>=b && y<=d))
//         || (y=b || y=d) && (x>=a && x<=c))
//         return true
// }
bool within_rectangle(int x,int y)
{
    if(x>=a && x<=c && y>=b && y<=d) 
    return true;
    else return false; //必须有
}
int main()
{
    while(cin>>n>>a>>b>>c>>d)
    {
        while(n--)
        {
            int x,y;
            cin>>x>>y;
            if(within_rectangle(x,y)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl; 
        }
        cout<<endl;
    }
    return 0;
}
/*
2
0 0 4 5
1 1
5 8
3
1 2 5 7
0 6
3 4
5 5
*/

/*
YES
NO

NO
YES
YES
*/