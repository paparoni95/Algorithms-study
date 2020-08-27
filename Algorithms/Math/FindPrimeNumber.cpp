#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 어떤 수 N이 소수인지 아닌지 판별하는 방법
// 소량의 소수를 구할 때 적합
// 소수란 2보다 크거나 같고, N-1 보다 작거나 같은 자연수로 나눠 떨어지면 안됨.
// 여기서 2 ~ N-1로 나누는 것도 가능하지만,
// 2 * 4 = 4 * 2 처럼 대칭을 이루기 때문에
// 특정한 숫자의 제곱근까지만 약수의 여부를 검증하면 된다.
// 시간 복잡도 O(sqrt(N))

bool IsPrime(int n)
{
	if (n < 2) return false;
	// 2 <= i <= sqrt(N)
	// i * i <= n
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	vector<int> v = { 1, 19, 24, 65, 98, 37, 11, 33, 28 };
	for (int i = 0; i < v.size(); ++i)
	{
		if (IsPrime(v[i]))
			cout << v[i] << "는 소수입니다." << endl;
		else
			cout << v[i] << "는 소수가 아닙니다." << endl;
	}

	return 0;
}