#include <iostream>
using namespace std;

int n, k;
int dp[101][100001];
int w[101], v[101];

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

	// 1 ~ n 번째 물건을 돌아가며 탐색
	for (int i = 1; i <= n; i++)
	{
		// 가방 무게
		for (int j = 1; j <= k; j++)
		{
			if (j >= w[i])
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];
	return 0;
}