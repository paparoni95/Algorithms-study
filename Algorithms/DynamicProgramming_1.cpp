#include <iostream>
using namespace std;

// 단순하게 분할 정복 기법을 이용해서 피보나치 수열을 구한다면
// 시간 복잡도 O(2^N)

int fibonacci(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	return fibonacci(x - 1) + fibonacci(x - 2);
}

int main() {
	cout << fibonacci(10) << '\n';
	//cout << fibonacci(50) << '\n'; 많은 시간이 소요된다.
	return 0;
}
