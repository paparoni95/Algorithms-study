#include <bits/stdc++.h>
using namespace std;

int N, M, K, X;
vector<int> graph[300001];
bool visited[300001];

vector<int> answer;

void BFS(int start) {
	visited[start] = true;
	queue<pair<int,int>> q;
	q.push({ start, 0 });
	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (cost == K) answer.push_back(cur);

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cost + 1 });
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	
	BFS(X);

	sort(answer.begin(), answer.end());
	if (answer.size() == 0) cout << -1 << '\n';
	else {
		for (auto n : answer) cout << n << '\n';
	}
	return 0;
}