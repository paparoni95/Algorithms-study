#include <iostream>
using namespace std;

int memo[10000000 + 1];

long long f(long long k)
{
    if (k == 1) return 1;
    if (k > 10000000)
    {
        if (k % 2 != 0) return f(3 * k + 1) + 1;
        else return f(k / 2) + 1;
    }

    if (memo[k]) return memo[k];

    if (k % 2 != 0)
        memo[k] = f(3 * k + 1) + 1;
    else
        memo[k] = f(k / 2) + 1;

    return memo[k];
}

int main()
{
    int a, b;
    cin >> a >> b;

    int maxLen = 0, maxidx = 0;
    for (int i = a; i <= b; i++)
    {
        int len = f(i);
        if (len > maxLen)
        {
            maxLen = len;
            maxidx = i;
        }
    }

    cout << maxidx << ' ' << maxLen << '\n';
    return 0;
}
