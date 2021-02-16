#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long a[100000 + 1];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
        
    sort(a, a+n);
    
    int l = 0, r = n - 1;
    long long al = a[l], ar = a[r];
    long long diff, ans = al + ar;
    
    while(l < r)
    {
        diff = a[l] + a[r];
        if(abs(ans) > abs(diff))
        {
            ans = diff;
            al = a[l];
            ar = a[r];
        }
        
        if(diff <= 0) l++;
        else r--;
    }
    
    cout << al << ' ' << ar << endl;
    return 0;
}
