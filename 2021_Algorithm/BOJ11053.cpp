#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, ans = 1;
int dp[1001];
int arr[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
	return 0;
}