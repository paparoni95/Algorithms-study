#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    // 0 0 -> 1
    // not A and not B
    // not (A or B)
    cout<<!(a || b)<<endl;
    return 0;
}
