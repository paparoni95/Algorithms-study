#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
bool prime[1000001];

void eratosthenes() {
	prime[0] = prime[1] = true;
	for (int i = 2; i * i < 1000000; i++) {
		if (!prime[i]) {
			for (int j = i + i; j <= 1000000; j += i) {
				prime[j] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	eratosthenes();
	while (true) { //10¸¸
		cin >> n;
		if (n == 0) break;
		bool find = false;
		int end = n / 2;
		for (int i = 2; i <= end; i++) {
			if (!prime[i] && !prime[n - i]) {
				cout << n << " = " << i << " + " << n - i << '\n';
				find = true;
				break;
			}
		}

		if (!find)
			cout << "Goldbach's conjecture is wrong.\n";
	}
	return 0;
}