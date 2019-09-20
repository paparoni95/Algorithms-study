#include <iostream>
using namespace std;

// 2*N 타일링 문제 (BOJ 11726)
int memo[1001];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (memo[x] != 0) return memo[x];
	return memo[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}

int main() {
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}