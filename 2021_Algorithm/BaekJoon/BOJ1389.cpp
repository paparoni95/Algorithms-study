#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, ans = 987654321, ans_node;
vector<int> adj[101];
bool vis[101];
int dist[101];

void bfs(int cur) {
	fill(dist, dist + 101, 0);
	fill(vis, vis + 101, false);

	queue<int> q;
	q.push(cur);
	vis[cur] = true;
	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < adj[node].size(); i++) {
			int next = adj[node][i];
			if (!vis[next]) {
				vis[next] = true;
				dist[next] = dist[node] + 1;
				q.push(next);
			}
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++) total += dist[i];
	if (ans > total) {
		ans = total;
		ans_node = cur;
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
	}

	cout << ans_node << '\n';
	return 0;
}