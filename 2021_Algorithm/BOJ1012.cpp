#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int board[51][51];
int n, m, k, ans;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	board[x][y] = 0;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (board[nx][ny])
			{
				board[nx][ny] = 0;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> m >> n >> k;

		fill(board[0], board[0] + 51 * 51, 0);
		ans = 0;

		int x, y;
		for (int i = 0; i < k; i++)
		{
			cin >> y >> x;
			board[x][y] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board[i][j])
				{
					ans++;
					bfs(i, j);
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}