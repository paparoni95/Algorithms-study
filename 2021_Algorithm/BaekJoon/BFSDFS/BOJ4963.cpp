#include <iostream>
#include <queue>
using namespace std;

const int MAX = 50;
const int dx[] = { 0,0,-1,1,-1,-1,1,1 };
const int dy[] = { 1,-1,0,0,-1,1,-1,1 };

int w, h;
int land[MAX][MAX];
bool vis[MAX][MAX];

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

		for (int i = 0; i < 8; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (land[nx][ny] == 1 && !vis[nx][ny])
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

	while (1)
	{
		fill(vis[0], vis[0] + MAX * MAX, false);

		cin >> w >> h;

		if (w == 0 && h == 0) break;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> land[i][j];
			}
		}

		int cnt = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (land[i][j] && !vis[i][j])
				{
					cnt++;
					bfs(i, j);
				}
			}
		}

		cout << cnt << '\n';
	}

	return 0;
}