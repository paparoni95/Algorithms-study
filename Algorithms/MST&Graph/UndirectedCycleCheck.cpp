#include <bits/stdc++.h>
using namespace std;

// DisjointSet은 무방향 그래프 내에서의 사이클을 판별할 때 사용할 수 있다.
// 각 간선을 확인하며 두 노드의 루트 노드를 확인한다.
// 루트 노드가 서로 다르다면, Union 연산을 수행하고,
// 같다면, 사이클이 발생한 것이다.

// 노드의 개수 v, 간선(union 연산)의 개수 e
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
int parent[100001];

// 특정 원소가 속한 집합을 찾기
int FindParent(int x) {
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
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

	bool cycle = false; // 사이클 발생 여부

	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		// 사이클이 발생한 경우 종료
		if (FindParent(a) == FindParent(b)) {
			cycle = true;
			break;
		}
		// 사이클이 발생하지 않았다면 합집합(Union)연산 수행
		else {
			UnionParent(a, b);
		}
	}

	if (cycle) {
		cout << "사이클이 발생했습니다.\n";
	}
	else {
		cout << "사이클이 발생하지 않았습니다.\n";
	}
	return 0;
}