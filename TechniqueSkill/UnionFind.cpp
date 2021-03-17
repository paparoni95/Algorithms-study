#include <iostream>
using namespace std;

/*
	# 서로소 집합
	공통 원소가 없는 두 집합을 말한다.
	집합 간의 관계를 파악하기 위해서 서로소 집합 알고리즘을 사용할 수 있다.

	# 서로소 집합 알고리즘 (union-find)
	union : 2개의 원소가 포함된 집합을 하나의 집합으로 합치는 연산
	find  : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산(루트 노드를 찾아줌)
	모든 노드는 자신이 속한 집합을 찾을 때 루트 노드를 재귀적으로 찾는다.
	이 때, 경로 압축 기법을 사용하면 더 빠르게 찾을 수 있다.

	# 시간 복잡도
	노드의 개수 V, 최대 V - 1개의 union연산, M개의 find 연산일 때
	O(V + MlogV)
*/

int v, e;
int parent[100001];

// 특정 원소가 속한 집합을 찾기
int findParent(int x)
{
	// 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	// 보통 더 작은 수가 루트 노드가 되도록 해준다.
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;

	// 부모를 자기 자신으로 초기화
	for (int i = 1; i <= v; i++) parent[i] = i;

	// union 연산을 수행
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	// 각 원소가 속한 집합 출력하기
	cout << "각 원소가 속한 집합: ";
	for (int i = 1; i <= v; i++) cout << findParent(i) << ' ';
	cout << '\n';

	// 부모 테이블 내용 출력하기
	cout << "부모 테이블: ";
	for (int i = 1; i <= v; i++) cout << parent[i] << ' ';
	cout << '\n';

	return 0;
}