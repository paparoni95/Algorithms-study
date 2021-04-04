#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 어떻게 촌수를 표현할 지?
vector<int> v[101];
bool vis[101];
int n, m, x, y;

int bfs()
{
	queue<pair<int, int>> q;
	q.push({ x,0 });
	vis[x] = true;
	while (!q.empty())
	{
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();

		if (now == y) return cost;

		for (int i = 0; i < v[now].size(); ++i)
		{
			int next = v[now][i];
			if (!vis[next])
			{
				vis[next] = true;
				q.push({ next,cost + 1 });
			}
		}
	}

	// 두 사람이 친척 관계가 없다.
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> n >> x >> y >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	cout << bfs() << '\n';
	return 0;
}