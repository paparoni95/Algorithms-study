#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int picked[8];
void dfs(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int previous = -1;
	for (int i = idx; i < n; i++) {
		if (previous != v[i]) {
			previous = v[i];
			picked[cnt] = v[i];
			dfs(cnt + 1, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	dfs(0, 0);
	return 0;
}