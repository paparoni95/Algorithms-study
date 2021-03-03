#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string a, b;
int dp[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> a >> b;

	int aSize = a.size();
	int bSize = b.size();

	for (int i = 1; i <= aSize; i++)
	{
		for (int j = 1; j <= bSize; j++)
		{
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[aSize][bSize];
	return 0;
}