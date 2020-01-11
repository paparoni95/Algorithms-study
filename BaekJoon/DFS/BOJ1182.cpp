#include <iostream>
#include <vector>
using namespace std;

int n, s;
int ans;

void solve(const vector<int>& a, int i, int sum, int goal) {
	// 정답인 경우
	if (sum == goal && i == a.size()) {
		ans += 1;
		return;
	}
	// 불가능한 경우
	if (i == a.size() && sum != goal) {
		return;
	}

	// 다음의 경우
	solve(a, i + 1, sum + a[i], goal);
	solve(a, i + 1, sum, goal);
}

int main() {
	cin >> n >> s;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	solve(v, 0, 0, s);
	// 합이 0일때 즉, 모든 경우를 선택하지 않은 경우가 존재하므로
	// 정답의 경우에서 -1을 해준다. (공집합이므로)
	if (s == 0) {
		cout << ans - 1;
	}
	else {
		cout << ans;
	}
	return 0;
}