#include <iostream>
#include <vector>
using namespace std;

vector<int> a[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	for (int i = 0; i < a[node].size(); i++) {
		int next_node = a[node][i];
		if (check[next_node] == false) {
			dfs(next_node);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int ans = 0; // 연결 요소의 개수
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
	return 0;
}