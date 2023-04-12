#include <iostream>
#include <string>
#include <algorithm>
// #include <bits/stdc++.h>
using namespace std;

string add(string A, string B)
{
	string C;
	int carry = 0; //进位
	//计数每个字符串未经加法运算的位数
	//A还有或B还有或AB同位进位，三种情况下继续运行
	for(int i = A.size()-1,j = B.size()-1;i>=0 || j>=0 || carry>0 ; i--,j--)
	{	
		if(i>=0) carry+=A[i]-'0';
		if(j>=0) carry+=B[j]-'0';
		// C[i] = '0' + carry%10; //没定义大小你就想赋值？
		C += '0'+ carry%10 ;
		carry /= 10;
	}
	reverse(C.begin(),C.end());
	return C;
}


int main()
{
	string A,B;
	cin>>A>>B;
	cout<<add(A,B);
	return 0;

}