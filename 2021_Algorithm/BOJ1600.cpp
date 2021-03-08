#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int horseX[] = { -1,-2,-2,-1,1,2,2,1 };
const int horseY[] = { -2,-1,1,2,-2,-1,1,2 };
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int k, r, c;
int a[201][201];
int dist[31][201][201]; // (x,y)에서 k번 능력을 사용해서 온 비용

struct Monkey
{
	int x, y, used;
};

void input()
{
	cin >> k >> c >> r;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
}

int bfs()
{
	queue<Monkey> q;
	q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		Monkey cur = q.front();
		q.pop();

		if (cur.x == r - 1 && cur.y == c - 1) return dist[cur.used][cur.x][cur.y];

		if (cur.used < k) // 능력이 남았다면 사용하기
		{
			for (int i = 0; i < 8; i++) // 능력을 사용했을 때
			{
				int nx = cur.x + horseX[i];
				int ny = cur.y + horseY[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
				if (dist[cur.used + 1][nx][ny] == -1 && a[nx][ny] == 0)
				{
					dist[cur.used + 1][nx][ny] = dist[cur.used][cur.x][cur.y] + 1;
					q.push({ nx,ny,cur.used + 1 });
				}
			}
		}

		for (int i = 0; i < 4; i++) // 능력을 사용하지 않을 때
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (dist[cur.used][nx][ny] == -1 && a[nx][ny] == 0)
			{
				dist[cur.used][nx][ny] = dist[cur.used][cur.x][cur.y] + 1;
				q.push({ nx,ny,cur.used });
			}
		}
	}

	return -1;
}

void solve()
{
	input();
	int ret = bfs();
	cout << ret << '\n';
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}