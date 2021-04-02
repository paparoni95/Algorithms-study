#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int n, maxH, ans;
int field[100][100];
bool vis[100][100];

// 물에 잠기지 않는 안전한 영역의 최대 개수
void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = true;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (!vis[nx][ny])
			{
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> field[i][j];
			maxH = max(maxH, field[i][j]);
		}
	}

	// 0 ~ maxH
	for (int h = 0; h <= maxH; ++h)
	{
		fill(vis[0], vis[0] + 100 * 100, false);

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (field[i][j] <= h)
					vis[i][j] = true;
			}
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!vis[i][j])
				{
					cnt++;
					bfs(i, j);
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}