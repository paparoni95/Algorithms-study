#include <iostream>
using namespace std;

#define MOD 1000000000

int d[101][10];
int n;

int main()
{
	cin >> n;

	for (int i = 1; i <= 9; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				d[i][j] = d[i - 1][j + 1] % MOD;
			}
			else if (j == 9)
			{
				d[i][j] = d[i - 1][j - 1] % MOD;
			}
			else {
				d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % MOD;
			}
		}
	}

	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];

	cout << ans % MOD;
	return 0;
}