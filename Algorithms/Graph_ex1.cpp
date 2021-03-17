#include <iostream>
using namespace std;
const int MAX = 100001;
int n, m;
int parent[MAX];

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

	for (int i = 0; i < m; i++)
	{
		int op, a, b;
		cin >> op >> a >> b;
		if (op == 0) // union
		{
			unionParent(a, b);
		}
		else // find
		{
			if (findParent(a) == findParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}