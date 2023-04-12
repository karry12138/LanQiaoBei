//输入若干组三角形三边，求面积（保留两位小数）
//000代表输入结束，不成三角形则输出No
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

bool is_triangle(double a,double b,double c)
{
    if((a+b>c)&&(a+c>b)&&(b+c>a)) return true;
    else return false;
}
double sin_(double a,double b,double c)
{
    double cosB = (pow(a,2)+pow(c,2)-pow(b,2))/(2*a*c);
    double sinB = sqrt(1-pow(cosB,2));
    return sinB;
}
double area(double a,double b, double c)
{
    double sinB = sin_(a,b,c);
    return 0.5*a*c*sinB;
}
int main()
{
    double a,b,c;
    while(cin>>a>>b>>c)
    {
        if(a==0&&b==0&c==0) break;
        if(is_triangle(a,b,c)) cout<<fixed<<setprecision(2)<<area(a,b,c)<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
3 4 5
2 2 2
1 2 3
0 0 0
*/
/*
6.00
1.73
No
*/