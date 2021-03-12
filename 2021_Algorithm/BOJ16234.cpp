#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n, l, r, ans;
int a[51][51];
int b[51][51];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int dfs(int x, int y, int color)
{
	int cnt = 1;
	b[x][y] = color;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (b[nx][ny] != 0) continue;

		int diff = abs(a[x][y] - a[nx][ny]);
		if (diff >= l && diff <= r)
		{
			cnt += dfs(nx, ny, color);
		}
	}

	return cnt;
}

void move(int color)
{
	int sum = 0, cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <n; j++)
			if (b[i][j] == color)
			{
				sum += a[i][j];
				cnt++;
			}

	int avg = sum / cnt;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if (b[i][j] == color)
			{
				a[i][j] = avg;
			}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int mark = 1;
	while (1)
	{
		memset(b, 0, sizeof(b));
		mark = 1;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i][j] == 0)
				{
					int ret = dfs(i, j, mark);
					if (ret > 1) mark++;
					else b[i][j] = 0;
				}
			}
		}

		if (mark == 1) break;

		for (int i = 1; i < mark; i++)
		{
			move(i);
		}

		ans++;
	}

	cout << ans << '\n';
	return 0;
}
