#include <iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    // 0 0 -> 1
    // 1 1 -> 1
    cout<<((!a && !b) || (a && b))<<endl;
    return 0;
}
