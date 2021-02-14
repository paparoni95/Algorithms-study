#include <iostream>
using namespace std;

int main()
{
    int w,h,b;
    cin>>w>>h>>b;
    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<(w*h*b) / (float)(1024*1024*8) << " MB\n";
    return 0;
}
