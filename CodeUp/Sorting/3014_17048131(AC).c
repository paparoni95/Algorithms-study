#include <stdio.h>

int a[100000 + 1];

int main()
{
    int n, temp;
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        a[temp]++;
    }
    
    for(int i=0;i<=100000;i++)
    {
        for(int j=1;j<=a[i];j++)
            printf("%d ",i);
    }
    
    return 0;
}
