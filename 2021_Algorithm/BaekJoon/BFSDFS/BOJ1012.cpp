#include <iostream>
#include <queue>
using namespace std;

int board[51][51];
bool vis[51][51];
int T, M, N, K;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void bfs(int x, int y)
{
	vis[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] == 1 && vis[nx][ny] == false)
			{
				vis[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	while (T--)
	{
		fill(board[0], board[0] + 51 * 51, 0);
		fill(vis[0], vis[0] + 51 * 51, false);

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> y >> x;
			board[x][y] = 1;
		}

		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1 && vis[i][j] == false)
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