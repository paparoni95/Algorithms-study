//https://www.acmicpc.net/problem/1463
#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dp[MAX];

int makeOne(int n) {
	dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		/* 1을 뺀다. */
		dp[i] = dp[i - 1] + 1;
		/* 2로 나누어 떨어지면, 2로 나눈다. */
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		/* 3으로 나누어 떨어지면, 3으로 나눈다. */
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);

	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << makeOne(n);
	return 0;
}