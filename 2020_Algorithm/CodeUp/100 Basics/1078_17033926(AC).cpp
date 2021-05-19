#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int total = 0;
    for(int i = 1; i <= n; i++)
    {
        if(i % 2 == 0)
            total += i;
    }
    
    cout<<total<<endl;
    return 0;
}
