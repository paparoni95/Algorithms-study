#include <bits/stdc++.h>
using namespace std;

int v, e;
int parent[100001];
vector<pair<int, pair<int, int> > > edges;
int result;

int FindParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
		edges.push_back({ cost, {a,b} });
	}

	// 간선을 비용순으로 정렬
	sort(edges.begin(), edges.end());
	int last = 0; // 최소 신장 트리에 포함되는 간선 중에서 가장 비용이 큰 간선

	// 간선을 하나씩 확인하면서
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// 사이클이 발생하지 않는 경우에만 집합에 포함
		if (FindParent(a) != FindParent(b)) {
			UnionParent(a, b);
			result += cost;
			last = cost;
		}
	}

	cout << result - last << '\n';
	return 0;
}