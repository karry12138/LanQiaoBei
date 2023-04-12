//cmath中包含反三角函数.asin(),acos()等
//acos()返回 [0,pi],配合余弦函数可用三边求角度
//一行输入六个实数，表示A,B,C三点坐标，求角ABC
//cosB = (a^2+c^2-b^2)/(2*a*c)

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double A,B,C;  //一次返回多个值的替代方案，设置全局变量并修改
const double PI = 3.1415926;
const double rad = 180/PI;

void length(double a1, double a2, double b1, double b2, double c1, double c2)
{
    A = sqrt(pow(b1-c1,2)+pow(b2-c2,2));
    B = sqrt(pow(a1-c1,2)+pow(a2-c2,2));
    C = sqrt(pow(a1-b1,2)+pow(a2-b2,2));
    // double A = sqrt(pow(b1-c1,2)+pow(b2-c2,2));
    // double B = sqrt(pow(a1-c1,2)+pow(a2-c2,2));
    // double C = sqrt(pow(a1-b1,2)+pow(a2-b2,2));
    //最初版本的滑稽错误，这仅仅创建并摧毁了三个临时变量，没有改变全局变量
}
double cosB_(double A,double B, double C)
{
    return (pow(A,2)+pow(B,2)-pow(C,2))/(2*A*C);
}

int main()
{
    double a1,a2,b1,b2,c1,c2;
    while(cin>>a1>>a2>>b1>>b2>>c1>>c2)
    {
        length(a1,a2,b1,b2,c1,c2);
        cout<<fixed<<setprecision(2)<<acos(cosB_(A,B,C))*rad<<endl;
    }
    return 0;
}
