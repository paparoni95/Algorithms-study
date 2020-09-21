#include <bits/stdc++.h>
using namespace std;

// DisjointSet (서로소 집합)
// Find 함수에서 경로 압축 기법을 이용하면 더 빠르게 동작할 수 있다.
// 노드의 개수가 V개, 최대 V - 1개의 Union 연산과 M개의 Find 연산이 가능할 때,
// 시간 복잡도 O(V + MlogV)

int v, e;
int parent[100001];

int FindParent(int x) {
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	// 경로 압축 기법
	// 각 노드에 대하여 find 함수를 호출한 이후에, 해당 노드의 루트 노드가 바로 부모 노드가 되도록
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

	// 부모 테이블 내용 출력하기
	cout << "부모 테이블: ";
	for (int i = 1; i <= v; i++) {
		cout << parent[i] << ' ';
	}
	cout << '\n';

	// 경로압축을 할려면, 전체적으로 Find 연산을 한 번 더 해줘야 한다.
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