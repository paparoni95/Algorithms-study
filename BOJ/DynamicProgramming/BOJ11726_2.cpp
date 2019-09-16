#include <iostream>
using namespace std;

int d[1001]; // d[i] = 2 * i를 채우는 방법의 수

int solution(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	else {
		if (d[n] > 0) return d[n];
		d[n] = (solution(n - 1) + solution(n - 2)) % 10007;
	}

	return d[n];
}

int main() {
	int n;
	cin >> n;

	cout << solution(n);

	return 0;
}