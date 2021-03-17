#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 탑승구
int g, p;
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
	freopen("input.txt", "r", stdin);

	cin >> g >> p;

	for (int i = 1; i <= g; i++) parent[i] = i;

	int cnt = 0;
	for (int i = 0; i < p; i++)
	{
		int x;
		cin >> x;
		int root = findParent(x); // 현재 비행기의 탑승구의 루트 확인
		if (root == 0) break;     // 현재 루트가 0이라면 종료
		unionParent(root, root - 1); // 바로 왼쪽의 집합과 합치기
		cnt++;
	}

	cout << cnt << '\n';
	return 0;
}