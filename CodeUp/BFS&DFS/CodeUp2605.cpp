#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int candy[7][7];
bool check[7][7];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y, int color)
{
	int cnt = 1;
	queue<pair<int, int> > q;
	q.push({ x,y });
	check[x][y] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 7 && ny < 7)
			{
				if (candy[nx][ny] == color && check[nx][ny] == false)
				{
					check[nx][ny] = true;
					cnt++;
					q.push({ nx,ny });
				}
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			cin >> candy[i][j];

	int ans = 0;
	for (int color = 1; color <= 5; color++)
	{
		memset(check, false, sizeof(check));

		for (int i = 0; i < 7; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				if (candy[i][j] == color && check[i][j] == false)
				{
					int cnt = bfs(i, j, color);
					if (cnt >= 3) ans++;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}