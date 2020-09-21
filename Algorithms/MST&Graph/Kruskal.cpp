#include <bits/stdc++.h>
using namespace std;

// 신장 트리 중에서 최소 비용으로 만들 수 있는 신장 트리를 찾는 알고리즘
// 크루스칼 알고리즘은 가장 거리가 짧은 간선부터 차례대로 집합에 추가하거나 추가하지 않는다.
// 시간 복잡도 O(ElogE)
// 시간이 가장 오래 걸리는 부분은 정렬 부분이므로, 서로소 집합 알고리즘의 시간 복잡도는 무시한다.

// 노드의 개수 v, 간선(union)의 개수 e
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
int parent[100001];
// 모든 간선을 담을 리스트와, 최종 비용을 담을 변수
vector<pair<int, pair<int, int> > > edges;
int result;

// 특정 원소가 속한 집합을 찾기
int FindParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = FindParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
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

	// 모든 간선에 대한 정보를 입력 받기
	for (int i = 0; i < e; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 비용순으로 정렬하기 위해서 튜플의 첫 번째 원소를 비용으로 설정
		edges.push_back({ cost, {a,b} });
	}
	
	// 간선을 비용순으로 정렬
	sort(edges.begin(), edges.end());

	// 간선을 하나씩 확인하며
	for (int i = 0; i < edges.size(); i++) {
		int cost = edges[i].first;
		int a = edges[i].second.first;
		int b = edges[i].second.second;
		// 사이클이 발생하지 않은 경우에만 집합에 포함
		if (FindParent(a) != FindParent(b)) {
			UnionParent(a, b);
			result += cost;
		}
	}

	cout << result << '\n';
	return 0;
}