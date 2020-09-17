#include <bits/stdc++.h>
using namespace std;

int n, m;
int result;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int min_value = 10001;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			min_value = min(min_value, x);
		}
		// '가장 작은 수'들 중에서 가장 큰 수 찾기
		result = max(result, min_value);
	}

	cout << result << '\n';
	return 0;
}