#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int picked[7];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		picked[cnt] = v[i];
		dfs(cnt + 1);
	}
}

int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;
	dfs(0);
	return 0;
}