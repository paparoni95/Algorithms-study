#include <iostream>
using namespace std;

int main()
{
    int a,d,n;
    cin>>a>>d>>n;
    int idx = 1;
    int sum = a;
    
    do
    {
        if(idx == n)
        {
            cout<<sum<<endl;
            break;
        }
        idx++;
        sum += d;
    }while(1);
    return 0;
}
