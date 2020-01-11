#include <iostream>
using namespace std;

// 타일 채우기 (BOJ 2133)

int memo[1001];

int dp(int x) {
	if (x == 0) return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (memo[x] != 0) return memo[x];
	int result = 3 * dp(x - 2);
	for (int i = 3; i <= x; i++) {
		if (x % 2 == 0) {
			result += 2 * dp(x - i);
		}
	}
	return memo[x] = result;
}

int main() {
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}