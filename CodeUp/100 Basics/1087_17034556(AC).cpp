#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i = 1;
    long long sum = 0;
    while(sum < n)
    {
        sum += i;
        i++;
    }
    cout<<sum<<endl;
    return 0;
}
