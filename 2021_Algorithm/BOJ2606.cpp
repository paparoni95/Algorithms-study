#include <iostream>
#include <queue>
#include <vector>

#define endl "\n"
#define MAX 101
using namespace std;

vector<int> com[MAX];
bool vis[MAX];
int n, m, ans;

void input()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		com[a].push_back(b);
		com[b].push_back(a);
	}
}

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < com[cur].size(); i++)
		{
			int next = com[cur][i];
			if (!vis[next])
			{
				ans++;
				q.push(next);
				vis[next] = true;
			}
		}
	}
}

void solve()
{
	input();
	bfs();
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