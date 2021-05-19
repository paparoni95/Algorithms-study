#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int h, n, m;
int a[101][101][101];
bool check[101][101][101];
const int dz[] = { 0,0,0,0,1,-1 };
const int dx[] = { 0,0,-1,1,0,0 };
const int dy[] = { 1,-1,0,0,0,0 };
bool ok = true;

queue<tuple<int,int,int> > tomatos;

void input()
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 1)
				{
					tomatos.push(make_tuple(i,j,k));
					a[i][j][k] = 0;
					check[i][j][k] = true;
				}
				if (a[i][j][k] == 0) ok = false;
			}
		}
	}
}

void bfs()
{
	while (!tomatos.empty())
	{
		int z, x, y;
		tie(z, x, y) = tomatos.front();
		tomatos.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nz >= 0 && nx >= 0 && ny >= 0 && nz < h && nx < n && ny < m)
			{
				if (check[nz][nx][ny] == false && a[nz][nx][ny] == 0)
				{
					check[nz][nx][ny] = true;
					a[nz][nx][ny] = a[z][x][y] + 1;
					tomatos.push(make_tuple(nz, nx, ny));
				}
			}
		}
	}
}

bool checkTomato()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (check[i][j][k] == false && a[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

int calcDay()
{
	int ret = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				ret = max(a[i][j][k], ret);
			}
		}
	}
	return ret;
}

void solve()
{
	input();
	// 처음부터 모든 토마토가 익어있는 상태라면 0을 출력
	if (ok)
	{
		cout << 0 << endl;
		return;
	}

	bfs(); // 토마토 익히기
	// 익지 않은 토마토가 있다면 -1을 출력
	if (!checkTomato()) cout << -1 << endl;
	else cout << calcDay() << endl;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}