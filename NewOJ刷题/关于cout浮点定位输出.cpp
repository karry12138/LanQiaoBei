#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int a, b, c;
    // cout.precision(2);
    while(cin >> a >> b >> c)
    {
        cout << a + b + c << endl;
        cout << fixed << setprecision(2) << (a + b + c) * 1.0 / 3 << endl;
    }
 
    return 0;
}