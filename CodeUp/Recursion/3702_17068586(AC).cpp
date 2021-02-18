#include <iostream>
using namespace std;

int memo[51][51];

int f(int n, int k)
{
    if(n == 1 || k == 1) return 1;
    if(memo[n][k]) return memo[n][k];
    
    return memo[n][k] = (f(n,k-1) + f(n-1,k)) % 100000000;
}

int main()
{
    int r, c;
    cin >> r >> c;
    
    cout << f(r, c) << '\n';
    return 0;
}
