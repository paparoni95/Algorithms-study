#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1001;
int n, m, s;
vector<int> adj[MAX];
bool visited[MAX];
vector<int> order;

void DFS(int start) {
	visited[start] = 1;
	order.push_back(start);
	for (int i = 0; i < adj[start].size(); ++i) {
		int next = adj[start][i];
		if (!visited[next]) {
			DFS(next);
		}
	}
}

void BFS(int start) {
	queue<int> q;
	visited[start] = 1;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		order.push_back(cur);
		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = 1;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> s;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(s);
	for (int i = 0; i < order.size(); ++i)
		cout << order[i] << " ";
	cout << "\n";

	memset(visited, false, sizeof(visited));
	order.clear();

	BFS(s);
	for (int i = 0; i < order.size(); ++i)
		cout << order[i] << " ";
	cout << "\n";

	return 0;
}