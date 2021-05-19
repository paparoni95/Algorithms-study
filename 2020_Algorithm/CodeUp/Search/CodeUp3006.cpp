#include <iostream>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    unsigned long long n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;

        unsigned long long left = 1, right = n, ans = 0;
        while (left <= right)
        {
            unsigned long long mid = (left + right) / 2;
            if (mid * mid <= n)
            {
                ans = mid * mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }

        cout << ans << '\n';
    }

    return 0;
}