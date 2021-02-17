#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define endl "\n"
using namespace std;

int n;
int edge[MAX][MAX];
vector<int> v[MAX];
bool vis[MAX];

vector<int> route;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> edge[i][j];

			if (edge[i][j] == 1)
				v[i].push_back(j);
		}
	}
}

void bfs(int x)
{
	queue<int> q;
	q.push(x);

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int next : v[cur])
		{
			if (!vis[next])
			{
				vis[next] = true;
				q.push(next);
				route.push_back(next);
			}
		}
	}
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << edge[i][j] << ' ';
		}
		cout << endl;
	}
}

void solve()
{
	input();

	fill(edge[0], edge[0] + MAX * MAX, 0);

	for (int i = 1; i <= n; i++)
	{
		route.clear();
		fill(vis, vis + MAX, false);

		bfs(i);

		for (int node : route)
		{
			edge[i][node] = 1;
		}
	}

	print();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();
	
	return 0;
}