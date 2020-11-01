#include <bits/stdc++.h>
using namespace std;

int v, e;
int indegree[100001];
vector<int> graph[100001];

vector<int> topologySort() {
	vector<int> result; // 경로 배열
	queue<int> q;

	// 진입차수가 0인 노드를 넣어준다.
	for (int i = 1; i <= v; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	// 모든 노드 반복
	for (int i = 1; i <= v; i++) {
		// n개의 노드를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
		if (q.empty()) {
			cout << "사이클이 발생\n";
			return result;
		}
		int now = q.front();
		q.pop();
		result.push_back(now);
		for (int j = 0; j < graph[now].size(); j++) {
			int next = graph[now][j];
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	return result;
}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		indegree[b]++;
	}

	vector<int> result = topologySort();
	for (auto n : result) {
		cout << n << ' ';
	}
	return 0;
}
