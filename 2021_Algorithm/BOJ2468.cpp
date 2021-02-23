#include <iostream>
#include <queue>
using namespace std;

int mp[101][101];
bool check[101][101];
int n, ans, maxH;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny]) continue;
			check[nx][ny] = true;
			q.push({ nx,ny });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mp[i][j];
			maxH = max(maxH, mp[i][j]);
		}
	}
		

	for (int h = 0; h <= maxH; h++)
	{
		fill(check[0], check[0] + 101 * 101, false);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (mp[i][j] <= h) 
					check[i][j] = true;

		int cnt = 0;
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (check[i][j] == false)
				{
					bfs(i, j);
					cnt++;
				}
			}

		ans = max(ans, cnt);
	}

	cout << ans << '\n';
	return 0;
}