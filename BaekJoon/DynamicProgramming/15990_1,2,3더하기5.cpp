#include <iostream>
using namespace std;

#define MOD 1000000009
#define LIMIT 100000

long long d[100001][4]; // d[i][j] : i를 1,2,3의 합으로 나타내는 방법의 수, 단 j는 마지막에 사용한 수라고 하면

int main()
{
	// 미리 답을 다 구해놓는다.
	d[1][1] = d[2][2] = d[3][3] = 1;
	d[3][1] = d[3][2] = 1;
	for (int i = 4; i <= LIMIT; i++)
	{
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % MOD;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % MOD;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % MOD;
	}

	// 문제해결
	int tc, n;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % MOD << '\n';
	}

	return 0;
}