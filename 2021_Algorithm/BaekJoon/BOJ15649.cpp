#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
bool alpha[8];
int picked[8];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << picked[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			picked[cnt] = v[i];
			dfs(cnt + 1);
			alpha[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) v[i] = i + 1;
	sort(v.begin(), v.end());
	dfs(0);
	return 0;
}
