#include <iostream>
using namespace std;

int main()
{
    int a[20][20] = {0,};
    int n,x,y;
    for(int i = 1; i <= 19; i++)
    {
        for(int j = 1; j <= 19; j++)
        {
            cin>>a[i][j];
        }
    }
    
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        int tmp = a[x][y];
        for(int j = 1; j <= 19; j++)
        {
            a[j][y] = !a[j][y];
            a[x][j] = !a[x][j];
        }
        a[x][y] = tmp;
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
