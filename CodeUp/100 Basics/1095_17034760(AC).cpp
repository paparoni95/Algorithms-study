#include <iostream>
using namespace std;

int main()
{
    int n,x;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    int minValue = 25;
    for(int i=0;i<n;i++)
    {
        if(minValue > arr[i])
            minValue = arr[i];
    }
    
    cout<<minValue<<endl;
    return 0;
}
