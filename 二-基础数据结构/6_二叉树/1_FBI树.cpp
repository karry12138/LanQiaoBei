//递归 完全二叉

// FBI树
// 定义三种字符串，全1为I类，全0为B类，同时含01为F类
// FBI树为节点数据是F,B,I类字符串的树
/*
由一个长度为2^n的01串S可以构造出一棵
FBI树T，递归的构造方法如下：
•T的根结点为R，其类型与串 S 的类型
相同；
•若串 S的长度大于 1，将串S 从中间分
开，分为等长的左右子串 S1 和S2；由
左子串 S1 构造 R的左子树 T1，由右子
串S2构造 R的右子树T2。
现在给定一个长度为2^n 的01 串，请用
上述构造方法构造出一棵 FBI 树，并输
出它的后序遍历序列。

0<=n<=10
input sample
3
10001011
output sample
IBFBBBFIBFIIIFF
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s[2000], tree[20000];

void build_FBI(int k,int left, int right) //k索引，第几个节点 left\right 字符串左右边界
{
    if(left==right){  //被2整除后边界相等
        if(s[left]=='1') tree[k]='I';
        else tree[k]='B';
        return ;  //结束此次调用
    }

    int mid = (left+right)/2;
    build_FBI(2*k,left,mid);  //递归构造左子树
    build_FBI(2*k+1,mid+1,right);  //递归构造右子树

    //完全构造完毕后，依据两个叶子节点决定父节点的值
    if(tree[2*k]=='B' && tree[2*k+1]=='B') tree[k]='B';   
    else if(tree[2*k]=='I' && tree[2*k+1] =='I') tree[k]='I';
    else tree[k]='F';
}

void postorder(int root)
{
    if(tree[2*root]) postorder(2*root);
    if(tree[2*root+1]) postorder(2*root+1);
    cout<<tree[root];
}

int main()
{
    int n;
    cin>>n;
    scanf("%s",s+1); //s+1表示，取s后面一位的地址 用s[1]-s[2000]
    build_FBI(1,1,strlen(s+1));
    postorder(1);
}