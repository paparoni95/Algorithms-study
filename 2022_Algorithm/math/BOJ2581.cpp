#include <iostream>
using namespace std;

int M, N;
bool notPrime[10001];

void eratosthenes()
{
	notPrime[0] = true;
	notPrime[1] = true;
	for (int i = 2; i < 10001; i++)
	{
		if (notPrime[i] == false)
		{
			for (int j = i + i; j < 10001; j += i)
			{
				notPrime[j] = true;
			}
		}
	}
}

// 대량의 소수를 구하는 알고리즘 => 에라토스테네스의 체

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	eratosthenes();

	cin >> M >> N;

	bool found = false;
	int ans = 0, total = 0;
	for (int i = M; i <= N; i++)
	{
		if (notPrime[i] == false)
		{
			if (found == false)
			{
				found = true;
				ans = i;
			}

			total += i;
		}
	}

	if (found == false)
	{
		cout << "-1\n";
	}
	else
	{
		cout << total << '\n' << ans << '\n';
	}

	return 0;
}