#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 101
#define endl "\n"
using namespace std;

bool vis[MAX][MAX];
int m, n, k, count;

vector<int> ans;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void input()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int a = x1; a < x2; a++)
		{
			for (int b = y1; b < y2; b++)
			{
				vis[a][b] = true;
			}
		}
	}
}

void dfs(int x, int y)
{
	vis[x][y] = true;
	count++;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (vis[nx][ny]) continue;
		dfs(nx, ny);
	}
}

void countBlock()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!vis[i][j])
			{
				count = 0;
				dfs(i, j);
				ans.push_back(count);
			}
		}
	}
}

void solve()
{
	input();
	countBlock();
	
	sort(ans.begin(), ans.end());

	cout << ans.size() << endl;
	for (int total : ans)
		cout << total << ' ';
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}