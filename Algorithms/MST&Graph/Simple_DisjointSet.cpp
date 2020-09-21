#include <bits/stdc++.h>
using namespace std;

// Union 연산은 노드 a와 노드 b를 합친다. (합집합)
// Find 연산은 해당 노드가 어느 집합에 속해 있는지 알려준다. (루트 노드를 반환함)
// 이를 Union-Find 자료구조라고 부른다.
// 시간 복잡도는 O(V), 최악의 경우 Find 함수가 모든 노드를 다 확인할 때가 있기 때문이다.

// 노드의 개수 v와 간선(Union 연산)의 개수 e
// 노드의 개수는 최대 100,000개라고 가정
int v, e;
// 부모 테이블 초기화
int parent[100001];

// 특정 원소가 속한 집합을 찾기
int FindParent(int x) {
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	return FindParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void UnionParent(int a, int b) {
	a = FindParent(a);
	b = FindParent(b);
	// 일반적으로 더 번호가 작은 원소가 부모 노드가 되도록 구현하는 경우가 많다.
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	cin >> v >> e;

	// 부모 테이블상에서, 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// Union 연산을 각각 수행
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		UnionParent(a, b);
	}

	// 각 원소가 속한 집합 출력하기
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i <= v; i++) {
		cout << FindParent(i) << ' ';
	}
	cout << '\n';

	// 부모 테이블 내용 출력하기
	cout << "부모 테이블: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n';
	return 0;
}