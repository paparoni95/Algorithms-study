#include <iostream>
using namespace std;

int main()
{
    long long h,b,c,s;
    cin>>h>>b>>c>>s;
    
    long long total = h * b * c * s;
    int tmp = 1024 * 1024 * 8;
    
    cout.setf(ios::fixed);
    cout.precision(1);
    cout<< total / (float)tmp << " MB\n";
    return 0;
}
