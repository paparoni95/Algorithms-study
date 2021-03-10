#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m, k, x;
vector<int> v[300001];
int dist[300001];
vector<int> ans;

void input()
{
	cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	memset(dist, -1, sizeof(dist));
}

void bfs()
{
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (dist[now] == k) ans.push_back(now);

		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			if (dist[next] == -1)
			{
				dist[next] = dist[now] + 1;
				q.push(next);
			}
		}
	}
}

void solve()
{
	input();
	bfs();
	if (ans.size() == 0) cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << '\n';
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);

	solve();

	return 0;
}