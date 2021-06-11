#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int picked[8];
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		picked[cnt] = v[i];
		dfs(i + 1, cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;
	dfs(0, 0);
	return 0;
}