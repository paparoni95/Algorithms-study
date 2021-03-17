#include <iostream>
#include <vector>
using namespace std;

// 여행 계획
int n, m;
int parent[501];
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
	freopen("input.txt", "r", stdin);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) parent[i] = i;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			if (x == 1) unionParent(i + 1, j + 1);
		}
	}
	
	vector<int > plan;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		plan.push_back(x);
	}

	bool ok = true;
	// 여행 계획에 속하는 모든 노드의 루트가 동일한지 확인
	for (int i = 0; i < m - 1; i++)
	{
		if (findParent(plan[i]) != findParent(plan[i + 1]))
		{
			ok = false;
		}
	}

	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}