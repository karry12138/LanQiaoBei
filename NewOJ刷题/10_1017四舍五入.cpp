//输入均为3位小数，四舍五入到小数点后第二位
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//setprecision自带四舍五入,但时不稳定，没法用
//round可以四舍五入到整数
int main() {
    double x;
    while(cin>>x)
    {
        x = round(x*100)/100.0;
        cout<<fixed<<setprecision(2)<<x<<endl;
    }
    return 0;
}
/*
2.055
0.154
10.159
99.999
3.565
*/

/*
2.06
0.15
10.16
100.00
3.57
*/
