#include <bits/stdc++.h>
using namespace std;

int n, k;
int result;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	while (n >= k) {
		// n이 k로 나누어 떨어지지 않는다면 1씩 빼기
		while (n % k != 0) {
			n--;
			result++;
		}

		// k로 나누기
		n /= k;
		result++;
	}

	// 마지막으로 남은 수에 대해여 1씩 빼기
	while (n > 1) {
		n--;
		result++;
	}

	cout << result << '\n';
	return 0;
}