#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s;
vector<int> graph[1001];
bool check[1001];

void dfs(int node) {
	check[node] = true;
	cout << node << ' ';
	for (int i = 0; i < graph[node].size(); i++) {
		int next_node = graph[node][i];
		if (check[next_node] == false) {
			dfs(next_node);
		}
	}
}

void bfs(int node) {
	queue<int> q;
	memset(check, false, sizeof(check));
	check[node] = true;
	q.push(node);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 0; i < graph[now].size(); i++) {
			int next_node = graph[now][i];
			if (check[next_node] == false) {
				check[next_node] = true;
				q.push(next_node);
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것 부터 먼저 탐색
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(s);
	cout << '\n';
	bfs(s);
	return 0;
}