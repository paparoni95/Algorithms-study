#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int i = 1, sum = 0;
    while(1)
    {
        sum += i;
        if(sum >= n)
        {
            cout<<i<<endl;
            break;
        }
        i++;
    }
    return 0;
}
