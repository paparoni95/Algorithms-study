#include <iostream>
using namespace std;

int a[10001]; // 셀프넘버면 0이고, 아니라면 1이다.

void SelfNumber(int number) {
	// d(75) = 75 + 7 + 5 = 87
	// d(n) = n + (n의 각 자리수)
	int sum = number;
	while (number) {
		sum += number % 10;
		number /= 10;
	}

	// 결과가 10000보다 작으면 그 숫자는 생성자가 있다는 뜻
	if (sum < 10000)
		a[sum] = 1;
}

int main() {
	// 먼저 d(n)을 다 구한다.
	for (int i = 1; i <= 10000; i++) {
		SelfNumber(i);
	}

	// 이중에서 0인 부분은 셀프넘버이므로 출력한다.
	for (int i = 1; i <= 9999; i++) {
		if (a[i] == 0) {
			cout << i << '\n';
		}
	}
	return 0;
}