#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin>>a>>b;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a%b<<endl;
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<a/(float)b<<endl;
    return 0;
}
