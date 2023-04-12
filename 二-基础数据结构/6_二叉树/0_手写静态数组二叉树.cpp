// 仅限完全二叉树
//从i起，左子树2*i,右子树2*i+1,父节点i/2

#include <iostream>
using namespace std;
const int N = 1000;

struct mytree2
{
    int data1;
    int data2;
}tree[N]; //使用1-N

// struct mytree
// {
//     int data;
//     int ls,rs; //左子树和右子树
// }tree[N];

// //DFS深度优先遍历

// //先序 中左右
// void preorder(mytree *root)
// {
//     cout<< root->data;
//     preorder(root->ls);
//     preorder(root->rs);
// }
// //中序 左中右
// void inorder(mytree *root)
// {
//     inorder(root->ls);
//     cout<< root->data;
//     inorder(root->rs);
// }

// //后序 左右中
// void postorder(mytree *root)
// {
//     postorder(root->ls);
//     postorder(root->rs);
//     cout<< root->data;
// }

//DFS深度优先遍历
//先序 中左右
void preorder(int root)
{
    cout<<tree[root].data1;
    if(tree[2*root].data1) preorder(2*root); //2*root为左子树索引
    if(tree[2*root+1].data1) preorder(2*root+1); //2*root+1为右子树索引
}
//中序 左中右
void inorder(int root)
{
    if(tree[2*root].data1) inorder(2*root); 
    cout<<tree[root].data1;
    if(tree[2*root+1].data1) inorder(2*root+1); 
}
//后序 左右中
void postorder(int root)
{
    if(tree[2*root].data1) postorder(2*root); 
    if(tree[2*root+1].data1) postorder(2*root+1);
    cout<<tree[root].data1;
}
int main()
{
    for(int i=1;i<=7;i++)
    {
        tree[i].data1 = i;
    }
    cout<<"按tree[1]-tree[7]赋值1-7"<<endl;
    cout<<"先序遍历";
    preorder(1);
    cout<<"\n中序遍历";
    inorder(1);
    cout<<"\n后序遍历";
    postorder(1);
    return 0;
}