#include <iostream>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n;
    
    int a[20][20]={0,};
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        a[x][y] = 1;
    }
    
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
