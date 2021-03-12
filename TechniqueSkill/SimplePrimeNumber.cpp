#include <iostream>
#include <cmath>
using namespace std;

// 소수 판별 함수, 시간 복잡도 O(sqrt(n))
bool isPrimeNumber(int x)
{
	// 2부터 x의 제곱근까지 모든 수를 확인하면서
	// x가 해당 수로 나누어떨어진다면 소수가 아니다.
	for (int i = 2; i <= (int)sqrt(x); i++)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	cout << isPrimeNumber(4) << endl;
	cout << isPrimeNumber(7) << endl;
	return 0;
}