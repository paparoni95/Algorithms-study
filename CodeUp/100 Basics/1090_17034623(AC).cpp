#include <iostream>
using namespace std;

int main()
{
    int a,r,n;
    cin>>a>>r>>n;
    int idx = 1;
    long long sum = a;
    do
    {
        if(idx == n)
        {
            cout<<sum<<endl;
            break;
        }
        idx++;
        sum *= r;
    }while(1);
    return 0;
}
