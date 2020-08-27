#include <iostream>
#include <vector>
using namespace std;

// 에라토스테네스의 체
// 대량의 소수를 빠르게 구하는 알고리즘
// O(NloglogN)

// 동작방식
// 1. 2 ~ N까지 모든 수를 써놓는다.
// 2. 아직 지워지지 않은 수 중에서 가장 작은 수를 찾는다.
// 3. 그 수는 소수이고,
// 4. 그 수의 배수는 모두 지운다.

const int MAX = 100001;
bool prime[MAX];

void eratosthenes()
{
	prime[1] = true;

	for (int i = 2; i <= MAX; ++i)
	{
		// 그 수가 소수라면
		if (prime[i] == false)
		{
			// 그 수의 배수들을 모두 지운다.
			for (int j = i + i; j <= MAX; j += i)
			{
				prime[j] = true;
			}
		}
	}
}

int main()
{
	// 대량의 소수를 구하고
	eratosthenes();

	// 구한 소수의 수를 센다.
	int cnt = 0;
	for (int i = 0; i < MAX; ++i)
		if (prime[i] == false)
			++cnt;

	cout << "총 소수의 수 : " << cnt << endl;
	return 0;
}