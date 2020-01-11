#include <iostream>
using namespace std;

bool prime[1000001]; 

// 2부터 100만까지 소수를 모두 구해놓는다. (에라토스테네스의 체)
// O(NloglogN)
void eratosthenes()
{
	prime[1] = true;

	// 아직 지워지지 않은 수 중에서 가장 작을 수를 찾는다.
	for (int i = 2; i <= 1000000; i++)
	{
		// 그 수가 소수라면
		if (prime[i] == false)
		{
			// 그 수의 배수를 모두 지운다.
			for (int j = i + i; j <= 1000000; j += i)
			{
				prime[j] = true;
			}
		}
	}
}

int main()
{
	eratosthenes(); // 미리 소수를 모두 구해놓고 문제를 해결한다.
	
	int n, m;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		if (prime[i] == false)
			cout << i << '\n';
	}

	return 0;
}