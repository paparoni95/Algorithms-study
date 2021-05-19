#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    if(n >= 90) cout<<"A";
    else if(n >= 70) cout<<"B";
    else if(n >= 40) cout<<"C";
    else cout<<"D";
    return 0;
}
