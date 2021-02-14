#include <iostream>
using namespace std;

int main()
{
    int a[101][101] = {0,};
    int h,w,n;
    cin>>h>>w>>n;
    
    int l,d,x,y;
    while(n--)
    {
        cin>>l>>d>>x>>y;
        if(d == 0) // 가로
        {
            for(int i = 0; i < l; i++)
            {
                a[x][y+i] = 1;
            }
        }
        else // 세로
        {
            for(int i = 0; i < l; i++)
            {
                a[x+i][y] = 1;
            }
        }
    }
    
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
