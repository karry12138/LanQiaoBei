/*
小蓝有很多数字卡片，每张卡片上都是数字 0 到 9。
小蓝准备用这些卡片来拼一些数，
他想从 1 开始拼出正整数，每拼一个，就保存起来，卡片就不能用来拼其它数了。
小蓝想知道自己能从 1 拼到多少。
例如，当小蓝有 30 张卡片，其中 0 到 9 各 3 张，
则小蓝可以拼出 1 到 10，但是拼 11 时卡片 1 已经只有一张了，不够拼出 11。
现在小蓝手里有 0 到 9 的卡片各 2021 张，共 20210 张，
请问小蓝可以从 1 拼到多少？提示：建议使用计算机编程解决问题。
*/

// 卡点在1上,看多少会用到2021张1
// 预估一下，3000多张

//到3500，有2100个1
//到3200,2040
//3190-2030
//3181-2021
#include <iostream>
using namespace std;

int main() {
    int n=3500;
    for(int i=1;i<=n;i++)
        cout<<i;
    return 0;
}  

