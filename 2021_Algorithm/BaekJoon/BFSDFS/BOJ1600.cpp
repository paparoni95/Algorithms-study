#include <iostream>
#include <queue>
using namespace std;

int mx[] = { 0,0,1,-1 };
int my[] = { 1,-1,0,0 };
int hx[] = { -1,-2,-2,-1,1,2,2,1 };
int hy[] = { -2,-1,1,2,-2,-1,1,2 };

int w, h, k;
int board[201][201];
bool vis[201][201][31]; // vis[x][y][k] : (x,y)지점에 능력을 k번 사용해서 왔습니다.

struct Monkey
{
	int x;
	int y;
	int cost;
	int used;
};

int bfs()
{
	queue<Monkey> q;
	q.push({ 0,0,0,0 });
	vis[0][0][0] = true;
	while (!q.empty())
	{
		Monkey m = q.front();
		q.pop();

		if (m.x == h - 1 && m.y == w - 1) return m.cost;

		// 말의 능력을 사용할 수 있다면
		if (m.used < k)
		{
			for (int i = 0; i < 8; ++i)
			{
				int nx = m.x + hx[i];
				int ny = m.y + hy[i];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (board[nx][ny] == 0 && !vis[nx][ny][m.used + 1])
				{
					vis[nx][ny][m.used + 1] = true;
					q.push({ nx,ny,m.cost + 1, m.used + 1 });
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = m.x + mx[i];
			int ny = m.y + my[i];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (board[nx][ny] == 0 && !vis[nx][ny][m.used])
			{
				vis[nx][ny][m.used] = true;
				q.push({ nx,ny,m.cost + 1, m.used });
			}
		}
	}

	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			cin >> board[i][j];
		}
	}

	cout << bfs() << '\n';
	return 0;
}