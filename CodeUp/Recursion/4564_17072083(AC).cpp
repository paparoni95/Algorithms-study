#include <iostream>
#include <algorithm>
using namespace std;

int memo[300 + 1];
int step[300 + 1];

int f(int k)
{
    if (k == 1) return memo[k] = step[1];
    if (k == 2) return memo[k] = max(step[1] + step[2], step[2]);
    if (k == 3) return memo[k] = max(step[1] + step[3], step[2] + step[3]);
    if (memo[k]) return memo[k];
    memo[k] = max(f(k - 3) + step[k - 1] + step[k], f(k - 2) + step[k]);
    return memo[k];
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> step[i];
    }

    cout << f(n) << '\n';
    return 0;
}
