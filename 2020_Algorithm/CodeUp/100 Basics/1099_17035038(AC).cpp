#include <iostream>
using namespace std;

int main()
{
    int a[11][11] = {0,};
    
    for(int i = 1; i <= 10; i++)
        for(int j = 1; j <= 10; j++)
            cin>>a[i][j];
    
    int x = 2, y = 2; // 개미의 위치
    
    while(1)
    {
        if(a[x][y] == 2)
        {
            a[x][y] = 9;
            break;
        }
        
        // 경로 표시
        a[x][y] = 9;
        
        // 맨 아래의 가장 오른쪽에 도착한 경우
        if(x == 9 && y == 9) break;
        
        if(y + 1 <= 10)
        {
            // 먹이를 발견했다면
            if(a[x][y+1] == 2)
            {
                a[x][y+1] = 9;
                break;
            }
            // 오른쪽이 벽이 아니라면 지나간다.
            else if(a[x][y+1] == 0)
            {
                y = y + 1;
                continue;
            }
        }
        
        if(x + 1 <= 10)
        {
            // 먹이를 발견했다면
            if(a[x+1][y] == 2)
            {
                a[x+1][y] = 9;
                break;
            }
            // 아래쪽이 벽이 아니라면 지나간다.
            else if(a[x+1][y] == 0)
            {
                x = x + 1;
                continue;
            }
        }
        
        // 더이상 움직일 수 없을 때
        break;
    }
    
    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <= 10; j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
