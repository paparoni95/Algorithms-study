#include <iostream>
using namespace std;

int d[1001]; // d[i] : 2 * i를 채우는 방법의 수

int main() {
	int n;
	cin >> n;

	d[1] = 1, d[2] = 2;
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + d[i - 2]) % 10007;
	}

	cout << d[n] % 10007;
	return 0;
}