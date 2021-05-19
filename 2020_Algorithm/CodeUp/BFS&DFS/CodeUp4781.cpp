#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int a[1001][1001];
int cnt[1001][1001];
bool check[1001][1001];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
bool ok = true;

queue<pair<int, int> > tomatos;

// 512MB = 512 * 1000 * 1000

void input()
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				tomatos.push({ i,j });
				check[i][j] = true;
			}
			else if (a[i][j] == 0) ok = false;
		}
	}
}

void bfs()
{
	while (!tomatos.empty())
	{
		int x = tomatos.front().first;
		int y = tomatos.front().second;
		tomatos.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m)
			{
				if (check[nx][ny] == false && a[nx][ny] == 0)
				{
					a[nx][ny] = 1;
					check[nx][ny] = true;
					cnt[nx][ny] = cnt[x][y] + 1;
					tomatos.push({ nx,ny });
				}
			}
		}
	}
}

bool checkTomato()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0 && check[i][j] == false)
				return false;
		}
	}
	return true;
}

int calcDay()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ret = max(ret, cnt[i][j]);
		}
	}
	return ret;
}

void solve()
{
	input();
	if (ok) // 토마토가 이미 모두 익은 상태라면
	{
		cout << 0 << endl;
		return;
	}

	bfs();

	if (!checkTomato())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << calcDay() << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}