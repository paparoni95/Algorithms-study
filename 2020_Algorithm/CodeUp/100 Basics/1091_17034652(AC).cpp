#include <iostream>
using namespace std;

int main()
{
    int a,m,d,n;
    cin>>a>>m>>d>>n;
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
        sum = sum * m + d;
    }while(1);
    return 0;
}
