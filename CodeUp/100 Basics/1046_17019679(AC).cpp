#include <iostream>
using namespace std;

int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    
    long long total = a+b+c;
    cout<<total<<endl;
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<<total / (float)3<<endl;
    return 0;
}
