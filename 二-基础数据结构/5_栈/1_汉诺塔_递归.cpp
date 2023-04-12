#include<iostream>
using namespace std;

const int N = 10000;
int sum=0,m;

void move(char A, char B, int n)
{
    sum++;
    if(sum==m) cout<<"#"<<n<<": "<<A<<"->"<<B<<endl;
}
void hanoi(char A, char B, char C, int n)
{
    if(n==1) move(A,C,n);
    else{
        hanoi(A,C,B,n-1);
        move(A,C,n);
        hanoi(B,A,C,n-1);
    }
}

int main()
{
    int n;
    cin>>n>>m;
    hanoi('A','B','C',n);
    cout<<sum<<endl;
    return 0;
}