#include <iostream>
#include <vector>
using namespace std;

/* 
   # 에라토스테네스의 체
   대량의 소수를 구하고 싶을 때 사용하는 알고리즘이다.

   # 알고리즘
   1. 2 ~ N까지의 모든 자연수를 나열
   2. 남은 수 중에서 아직 처리하지 않은 가장 작은 수 i를 찾는다.
   3. 남은 수 중에서 i의 배수를 모두 제거한다. (i는 제거하지 않는다)
   4. 더 이상 반복할 수 없을 때까지 2와 3을 반복한다.

   # 장점
   빠르게 대량의 소수들을 구할 수 있다.
   O(logNlogN)

   # 단점
   메모리가 많이 필요하다.
*/
int n = 1000;
vector<int> v(n + 1, 1);

int main()
{
	// 2부터 n의 제곱근까지의 모든 수를 확인하며
	for (int i = 2; i <= (int)sqrt(n); i++)
	{
		// i가 소수인 경우
		if (v[i] == 1)
		{
			// i를 제외한 i의 배수를 지우기
			int j = 2;
			while (i * j <= n)
			{
				v[i * j] = 0;
				j++;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (v[i] == 1) cout << i << ' ';
	}
	return 0;
}