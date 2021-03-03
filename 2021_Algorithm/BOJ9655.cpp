#include <iostream>
#include <vector>
using namespace std;

int n;
int dp[1001]; // 선공이 이기면 1, 지면 2

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (dp[i - 3] == 2 || dp[i - 1] == 2) dp[i] = 1;
		else dp[i] = 2;
	}

	if (dp[n] == 1) cout << "SK\n";
	else cout << "CY\n";
	return 0;
}