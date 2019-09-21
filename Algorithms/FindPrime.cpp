#include <iostream>
using namespace std;

// 하나의 숫자가 소수인지 판별하는 알고리즘
// 시간 복잡도 O(N^(1/2))
// 2 * 4 = 4 * 2와 같은 식으로 대칭을 이루기 때문에
// 특정한 숫자의 제곱근까지만 약수의 여부를 검증하면 된다.

bool isPrimeNumber(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return true;
}

int main() {
	cout << isPrimeNumber(97);
	return 0;
}