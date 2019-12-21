#include <iostream>
using namespace std;

#define MOD 1000000000

int d[101][10]; // d[n][i] : 길이가 N인 계단 수, 마지막에 오는 수 i

int main()
{
	int n;
	cin >> n;

	// 길이가 1인 계단 수
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	// 길이가 2인 계단 수
	for (int i = 2; i <= n; i++)
	{
		// 가장 뒤에 오는 숫자 0 ~ 9
		for (int j = 0; j <= 9; j++)
		{
			if (j - 1 >= 0)
				d[i][j] += d[i - 1][j - 1];
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];

			d[i][j] %= MOD;
		}
	}

	// 해당 길이가 N일 때의 모든 계단 수를 구하면
	long long ans = 0;
	for (int i = 0; i <= 9; i++)
		ans += d[n][i];

	cout << ans % MOD;
	return 0;
}