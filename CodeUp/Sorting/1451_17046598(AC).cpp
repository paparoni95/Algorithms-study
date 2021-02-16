#include <iostream>
#include <algorithm>

#define MAX 10000
#define endl "\n"
using namespace std;

int a[MAX];
int n;

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>a[i];
        
    sort(a, a + n);
    
    for(int i = 0; i < n; i++)
        cout<<a[i]<<endl;
    
    return 0;
}
