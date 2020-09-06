#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 그래프를 인접 행렬로 표현 => 시간 복잡도 O(V^2)

// 그래프의 인접리스트 표현 => 시간 복잡도 O(V + E)
vector<vector<int>> adj;
// start에서 시작해 그래프를 너비 우선 탐색하고 각 정점의 방문 순서를 반환
vector<int> BFS(int start) {
	// 각 정점의 방문 여부
	vector<bool> discovered(adj.size(), false);
	// 방문할 정점 목록을 유지하는 큐
	queue<int> q;
	// 정점의 방문 순서
	vector<int> order;
	discovered[start] = true;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		// here를 방문한다.
		order.push_back(here);
		// 모든 인접한 정점을 검사한다.
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i];
			// 처음 보는 정점이면 방문 목록에 집어넣는다.
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}