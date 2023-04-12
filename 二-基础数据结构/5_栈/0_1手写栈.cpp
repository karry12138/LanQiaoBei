#include <iostream>
using namespace std;
const int N = 10000;
struct mystack
{
    int A[N]={0};
    int t=-1; //栈顶
    void push(int x){ A[++t] = x; }//入栈
    int top() { return A[t]; }//返回栈顶
    void pop() { t--; } //弹出栈顶
    // int pop_return() { return A[t];t--; } //弹出栈顶
    int empty() {return (t==-1)?1:0;} //返回1表示空
}s1;

int main()
{
    mystack s;
    s.push(2);
    cout<<s.top()<<endl;
    cout<<"empty:"<<s.empty()<<endl;
    cout<<"pop"<<endl;
    s.pop();
    cout<<"empty:"<<s.empty()<<endl;
    return 0;
}