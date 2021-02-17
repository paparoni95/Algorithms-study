#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
#define endl "\n"
using namespace std;

int n, m, ans;
vector<int> v[MAX];
bool vis[MAX];

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (!vis[next])
			{
				vis[next] = true;
				q.push(next);
			}
		}
	}
}

void solve()
{
	input();

	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			bfs(i);
			ans++;
		}
	}

	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}