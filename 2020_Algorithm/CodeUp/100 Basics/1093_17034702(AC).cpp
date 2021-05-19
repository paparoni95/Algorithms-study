#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    int arr[24] ={0,};
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        arr[x]++;
    }
    
    for(int i = 1; i < 24; i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}
