#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[100001];

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
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;
		if (cmd == 0) {
			UnionParent(a, b);
		}
		else {
			if (FindParent(a) == FindParent(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}