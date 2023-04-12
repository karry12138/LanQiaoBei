// 字符串操作
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str ="123456789abcdefghiaklmn";

    for(int i=0;i<10;i++)   //把str看成一个字符串数组
        cout<<str[i]<<" ";
    cout << endl;

//find函数-返回子串定位首索引，若无返回-1
    cout<<"123的位置:   "<<str.find("123")<<endl;
//输出：123的位置:   0
    cout<<"34在str[2]到str[n-1]中的位置:   "<<str.find("34",2)<<endl;
//输出：34在str[2]到str[n-1]中的位置:   2
    cout<<"ab在str[0]到str[12]中的位置:    "<<str.rfind("ab",12)<<endl;
//输出：ab在str[0]到str[12]中的位置:    9

//substr()函数
    cout<<"str[3]及以后的子串:"<<str.substr(3)<<endl;
//输出：str[3]及以后的子串:456789abcdefghijklmn
//若小于限制长度则报错
    cout<<"从str[2]开始的4个字符:"<<str.substr(2,4)<<endl;
//输出：从str[2]开始的4个字符:3456

//find()函数
    str.replace(str.find("a"), 5, "@#");
    cout<<str<<endl;
//输出：123456789@#fghiaklmn

//insert()函数
    str.insert(2, "***");
    cout<<"从2号位置插入: "<<str<<endl;
//输出：12***3456789@#fghiaklmn

//添加字符串：append()函数
    str.append("$$$");
    cout<<"在字符串str后面添加字符串:"<<str<<endl;
//输出： 12***3456789@#fghiaklmn$$$

//字符串长度
    cout<<str.size()<<endl;
    cout<<str.length()<<endl;

//交换字符串：swap()函数
    string str1="aaa",str2="bbb";
    swap(str1, str2);
    cout<<str1<<"  "<<str2<<endl;

//字符串比较函数：compare()，相等输出0，不等输出1
    cout<<str1.compare(str2)<<endl;
    if(str1==str2) cout <<"==";   //直接比较也行
    if(str1!=str2) cout <<"!=";

    return 0;
}