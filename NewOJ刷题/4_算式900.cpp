/*
小明的作业本上有道思考题：算式： (□□□□-□□□□)*□□=900 
其中的小方块代表0~9的数字，这10个方块刚好包含了0~9中的所有数字。 
注意：0不能作为某个数字的首位。 
小明经过几天的努力，终于做出了答案！如下：(5012-4987)*36=900 
用计算机搜索后，发现还有另外一个解，本题的任务就是：请你算出这另外的一个解。 

输出格式需要与示例严格一致； 
括号及运算符号不要用中文输入法； 
整个算式中不能包含空格。 
*/

// // #include <iostream>
// // using namespace std;

// // int main()
// // {
// //     for(int i=1000;i<=9999;i++)
// //         for(int j=1000;j<=9999;j++)
// //             for(int k=10;k<=99;k++)
// //                 if((i-j)*k==900) cout<<"("<<i<<"-"<<j<<")*"<<k<<"=900"<<endl;
// //     return 0;
// // }
// //不考虑重复数字暴力算的结果太多了，大概9w条
// //不过托此发现，i-j与k只能为90的因数{10,12,15,18,20,25,30,36,45,50,60,75,90}12中情况
// //开始剪枝

// //这个错误后计数回档的问题真难搞
// //设置一个中间存档吧
// //一个不够，要两个
// #include <iostream>
// using namespace std;

// int number_exist[10] = {0};
// int data1[10]={0}; //中间一级存档
// int data2[10]={0}; //中间二级存档
// void init()
// {
//     for(int i=0;i<=9;i++)
//         number_exist[i] = 0;
// }

// //读取中间存档
// void load(int level)
// {   
//     if(level==1)//读取一级存档
//     {
//         for(int i=0;i<=9;i++)
//             number_exist[i]=data1[i];
//     }
//     else//读取二级存档 
//     {
//         for(int i=0;i<=9;i++)
//             number_exist[i]=data2[i];
//     }
// }
// //保存中间存档
// void save(int level)
// {
//     if(level==1)//存在一级档
//     {
//         for(int i=0;i<=9;i++)
//             data1[i]=number_exist[i];
//     }
//     else//存在二级档
//     {
//         for(int i=0;i<=9;i++)
//             data2[i]=number_exist[i];
//     }
// }

// //分割数字并计数+重复时读档
// //->将读档操作分离出去
// bool is_repeated(int x)
// {
//     int a1 = x%10;
//     int a2 = (x%100)/10;
//     int a3 = (x%1000)/100;
//     int a4 = x/1000;
    
//     if (number_exist[a1]==0) number_exist[a1]++;
//     else return true;  
//     if (number_exist[a2]==0) number_exist[a2]++;
//     else return true;  
//     // else{
//     //     load();  //若重复，回档
//     //     // number_exist[a1]--; //回档比手动撤销方便多了
//     //     // number_exist[a2]--;
//     //     return true;  
//     // } 
//     if (x>=1000)
//     {
//         if (number_exist[a3]==0) number_exist[a3]++;
//         else return true;  
//         // else{
//         //     load();  //若重复，回档
//         //     // number_exist[a1]--;
//         //     // number_exist[a2]--;
//         //     // number_exist[a3]--;
//         //     return true;  
//         // } 
//         if (number_exist[a4]==0) number_exist[a4]++;
//         else return true;  
//         // else{
//         //     load();  //若重复，回档
//         //     // number_exist[a1]--;
//         //     // number_exist[a2]--;
//         //     // number_exist[a3]--;
//         //     // number_exist[a4]--;
//         //     return true;  
//         // } 
//     }
//     return false;
// }

// // void show()
// // {
// //     for(int i=0;i<=9;i++)
// //         cout<<number_exist[i];
// //     cout<<endl;
// // }


// int main()
// {

//     // is_repeated(1999);
//     // show();
//     // cout<<is_repeated(1999)<<endl;

//     for(int i=1000;i<=9876;i++)
//     {
//         init();
//         if(is_repeated(i)) 
//         {   
//             init();
//             continue;
//         }
//         save(1); //存一级档
//         for(int j=1000;j<=9876;j++)
//         {
//             // fill(j); //问题在这里，遇到不满足的j，初始化数组时把i的计数一并抹除了
//             if(is_repeated(j))
//             { 
//                 if(j==9876) init();//若全部循环结束后仍不行，全部重置
//                 load(1); //若本次循环不行，读一档
//                 continue;
//             }
//             save(2);//存二级档
//             for(int k=10;k<=98;k++)
//             {               
//                 if(is_repeated(k))
//                 {  
//                     if(k==98) load(1);
//                     load(2);//若本次循环不行，读二档
//                     continue;
//                 }
//                 // 测试用 5690+1234+78 = 7002
//                 // if((i+j+k)==7002)
//                 // {
//                 //     cout<<"("<<i<<"+"<<j<<"+"<<k<<")=7002"<<endl;
//                 //     break;
//                 // } 
//                 if((i-j)*k==900)
//                 {
//                     cout<<"("<<i<<"-"<<j<<")*"<<k<<"=900"<<endl;
//                     break;
//                 }
//                 load(2);
                
//             }
//         }
//     }
//     return 0;
// }

//好吧，直接把代码塞上去，超时了,1800ms
//不过这是填空题，能直接写答案
//如果不是填空题，得想别的方法了，不过确实还有可以优化的地方

#include<iostream>
using namespace std;

int main()
{
    cout<<"(6048-5973)*12=900";
    return 0;
}
//哦，可以优化的是k,毕竟k只有12种情况