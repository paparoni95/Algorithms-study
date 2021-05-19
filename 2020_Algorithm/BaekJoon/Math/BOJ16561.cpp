#include <bits/stdc++.h>
using namespace std;

// 9 = 3 + 3 + 3
// 12 = 3 + 3 + 6
// 순서가 상관없으면 조합이다.
int n, ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	// 2개를 고르면 하나는 자동적으로 된다.
	for (int i = 1; i <= n / 3; i++) {
		for (int j = 1; j <= n / 3; j++) {
			int sum = i * 3 + j * 3;
			if ((n - sum) % 3 == 0 && sum < n) ans++;
		}
	}
	cout << ans;
	return 0;
}