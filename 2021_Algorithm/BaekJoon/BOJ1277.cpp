#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, W;
double M;
vector<pair<int, int>> pos;
vector<pair<int, double>> adj[1001];
double dist[1001];

void dijkstra() {
	fill(dist, dist + 1001, 1e9);
	priority_queue<pair<double, int>> pq;
	pq.push({ 0, 1 });
	dist[1] = 0;
	while (!pq.empty()) {
		double curDistance = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (dist[curNode] < curDistance) continue;
		for (int i = 0; i < adj[curNode].size(); i++) {
			int nextNode = adj[curNode][i].first;
			double nextDistance = curDistance + adj[curNode][i].second;
			if (nextDistance < dist[nextNode]) {
				dist[nextNode] = nextDistance;
				pq.push({ -nextDistance, nextNode });
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> W >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> y >> x;
		pos.push_back({ x,y });
	}

	// 입력으로 주어지는 전깃줄
	for (int i = 0; i < W; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back({ b,0 });
		adj[b].push_back({ a,0 });
	}

	// 전깃줄을 모두 연결해보자.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			double d = hypot(pos[i].first - pos[j].first, pos[i].second - pos[j].second);
			if (d > M) continue;
			adj[i + 1].push_back({ j + 1,d });
		}
	}

	dijkstra();

	cout << (int)(dist[N] * 1000) << '\n';
	return 0;
}