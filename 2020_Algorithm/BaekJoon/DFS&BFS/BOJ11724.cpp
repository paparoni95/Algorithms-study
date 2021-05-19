#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int n, m, answer;
vector<int> adj[MAX];
bool visited[MAX];

void DFS(int start) {
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); ++i) {
		int next = adj[start][i];
		if (!visited[next])
			DFS(next);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			DFS(i);
			++answer;
		}
	}

	cout << answer;

	return 0;
}