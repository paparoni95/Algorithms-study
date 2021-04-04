#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e;
vector<int> computer[101];
bool vis[101];

int bfs()
{
	int cnt = 0;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < computer[now].size(); ++i)
		{
			int next = computer[now][i];
			if (!vis[next])
			{
				cnt++;
				vis[next] = true;
				q.push(next);
			}
		}
	}

	return cnt;
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin >> a >> b;
		computer[a].push_back(b);
		computer[b].push_back(a);
	}

	cout << bfs() << '\n';
	return 0;
}