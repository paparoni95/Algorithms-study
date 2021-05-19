#include <iostream>
using namespace std;

int memo[15][15];

int superSum(int k, int n)
{
    if(memo[k][n]) return memo[k][n];
    if(k == 0) return n;
    
    for(int i = 1; i <= n; i++)
        memo[k][n] += superSum(k - 1, i);
    
    return memo[k][n];
}

int main()
{
    int k, n;
    while(cin >> k >> n)
        cout << superSum(k, n) << '\n';
    
    return 0;
}
