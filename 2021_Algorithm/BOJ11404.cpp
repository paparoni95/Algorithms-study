#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int n, m;
int graph[101][101];

void input()
{
	cin >> n >> m;
	fill(graph[0], graph[0] + 101 * 101, INF);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}
}

void solve()
{
	input();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) graph[i][j] = 0;

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}