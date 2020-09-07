#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, a, b;
vector<vector<int>> adj;

vector<int> BFS(int start) {
	vector<int> visited(adj.size(), 0);
	vector<int> dist(adj.size(), 0);
	queue<int> q;
	visited[start] = 1;
	dist[start] = 0;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (!visited[next]) {
				dist[next] = dist[cur] + 1;
				visited[next] = 1;
				q.push(next);
			}
		}
	}
	return dist;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> m;
	adj.resize(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> answer = BFS(a);
	if (answer[b] != 0)
		cout << answer[b];
	else
		cout << -1;
	return 0;
}