//输入n(n<=1000),返回n!
//数组使用联系
#include <iostream>
using namespace std;

const int SIZE=10000;
int A[SIZE]={0};

int main()
{
    int n;
    cin>>n;
    A[0]=1; //initialize the first number
    for(int i=1;i<=n;i++) // for ever number to multiply
    {
        int carry = 0; //进位
        for(int j=0;j<SIZE;j++)//对大数组中的每一位
        {
            A[j] = A[j]*i + carry;
            carry = A[j] / 10;
            A[j] = A[j] % 10;  //向下一位进位后，该位的值
        }
    }
    int last = 10000-1; //找最高位
    while(A[last]==0)
    {
        last--;
    }
    for(int i=last;i>=0;i--)
    {
        cout<<A[i];
    }
    return 0;
}