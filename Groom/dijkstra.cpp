#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;

int n, m, s;

vector<int> dijkstra(vector < vector<pair<int, int>>>& a, vector<bool>& c, int start)
{
	vector<int> res(n + 1, INT_MAX);
	c[start] = true, res[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (res[cur] < cost) continue; // 불필요한 연산이므로
		for (int i = 0; i < a[cur].size(); i++) {
			int next = a[cur][i].first;
			int distance = a[cur][i].second;
			if (res[next] > distance + cost) {
				res[next] = distance + cost;
				pq.push({ res[next], next });
			}
		}
	}
	return res;
}

int main() {
	cin >> n >> m;
	vector < vector<pair<int, int>>> a(n + 1);
	vector<bool> c(n + 1, false);
	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		// 양방향
		a[u].push_back({ v,c });
		a[v].push_back({ u,c });
	}
	cin >> s;
	vector<int> res = dijkstra(a, c, s);
	for (int i = 1; i <= n; i++) {
		cout << i << ": " << res[i] << '\n';
	}
	return 0;
}