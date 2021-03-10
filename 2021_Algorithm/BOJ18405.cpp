#include <iostream>
#include <queue>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
int a[201][201];
int n, k, s, x, y;
queue<pair<int, int>> q;

void input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	cin >> s >> x >> y;

	for (int virus = 1; virus <= k; virus++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == virus)
					q.push({ i,j });
			}
		}
	}
}

void bfs()
{
	while (s--)
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx < 1 || ny < 1 || nx >n || ny > n) continue;
				if (a[nx][ny] == 0)
				{
					a[nx][ny] = a[cx][cy];
					q.push({ nx,ny });
				}
			}
		}
	}
}

void solve()
{
	input();
	bfs();
	cout << a[x][y] << '\n';
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}