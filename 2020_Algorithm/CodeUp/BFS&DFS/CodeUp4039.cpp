#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int a[1000][1000];
bool check[1000][1000];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct Node
{
	int x, y, cost;
};

int bfs()
{
	queue<Node> q;
	q.push({ 0,0,1 });
	check[0][0] = true;
	while (!q.empty())
	{
		Node cur = q.front(); q.pop();

		if (cur.x == n - 1 && cur.y == m - 1) return cur.cost;

		for (int i = 0; i < 4; i++)
		{
			Node next = { cur.x + dx[i], cur.y + dy[i], cur.cost + 1 };
			if (next.x < 0 || next.y < 0 || next.x >= n || next.y >= m) continue;
			if (check[next.x][next.y]) continue;

			int diff = abs(a[cur.x][cur.y] - a[next.x][next.y]);
			if (diff > 1) continue;
			check[next.x][next.y] = true;
			q.push(next);
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}

	int ret = bfs();
	if (ret == -1) cout << 0 << '\n';
	else cout << ret << '\n';
	return 0;
}