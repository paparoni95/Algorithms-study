#include <iostream>
using namespace std;

// 소수를 대량으로 빠르고 정확하게 구하는 알고리즘

int a[100001];

void eratosthenes() {
	for (int i = 2; i <= 100000; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= 100000; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= 100000; j += i) {
			a[j] = 0; // 소수가 아니므로 지운다.
		}
	}
	for (int i = 2; i <= 100000; i++) {
		if (a[i] != 0)
			cout << a[i] << ' ';
	}
}

int main() {
	eratosthenes();
	return 0;
}