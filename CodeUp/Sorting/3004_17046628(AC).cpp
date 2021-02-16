#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 500001
using namespace std;

int num[MAX];

int main()
{
    int n;
    cin>>n;
    
    vector<int> v1(n, 0); // 기존 순서
    for(int i = 0; i < n; i++)
        cin>>v1[i];
        
    vector<int> v2 = v1;  // 오름차순 순서
    
    sort(v2.begin(), v2.end());
    
    for(int i = 0; i < n; i++)
        num[v2[i]] = i;
        
    for(int i = 0; i < n; i++)
    {
        cout<<num[v1[i]]<<' ';
    }
    
    return 0;
}
