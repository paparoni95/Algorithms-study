#include <iostream>
using namespace std;

/*
	# 서로소 집합을 활용한 사이클 판별
	무방향 그래프 내에서 사이클을 판별할 때 사용할 수 있다.
	방향 그래프는 DFS을 이용해서 판별할 수 있다.

	# 동작 방식
	1. 각 간선을 확인하면서 두 노드의 루트 노드를 확인한다.
	2. 루트 노드가 다르다면 두 노드에 대하여 union 연산을 수행
	3. 루트 노드가 서로 같다면 사이클이 발생한 것이다.
*/

int v, e;
int parent[100001];

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main()
{
	cin >> v >> e;

	for (int i = 1; i <= v; i++) parent[i] = i;

	bool cycle = false; // 사이클 발생 여부
	for (int i = 0; i < e; i++) // 각 간선을 확인한다
	{
		int a, b;
		cin >> a >> b;
		// 사이클이 발생한 경우 종료한다.
		// 즉, 두 루트 노드가 같다면 사이클이 발생한 것
		if (findParent(a) == findParent(b))
		{
			cycle = true;
			break;
		}
		else
			unionParent(a, b);
	}

	if (cycle)
		cout << "Cycle!\n";
	else
		cout << "NoCycle!\n";

	return 0;
}