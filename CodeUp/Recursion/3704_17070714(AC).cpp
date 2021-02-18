#include <iostream>
using namespace std;

int memo[100000 + 1];

int f(int k)
{
    if(k == 1) return 1;
    if(k == 2) return 2;
    if(k == 3) return 4;
    if(memo[k]) return memo[k];
    return memo[k] = (f(k-1)+f(k-2)+f(k-3)) % 1000;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << '\n';
    return 0;
}
