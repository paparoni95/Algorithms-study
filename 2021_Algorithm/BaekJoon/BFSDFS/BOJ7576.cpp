#include <iostream>
#include <queue>
using namespace std;

int box[1001][1001];
int cnt[1001][1001];
bool vis[1001][1001];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int M, N;

queue<pair<int, int >> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (box[nx][ny] == 0 && vis[nx][ny] == false)
			{
				box[nx][ny] = 1;
				vis[nx][ny] = true;
				cnt[nx][ny] = cnt[x][y] + 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int green_tomato = 0;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 0)
				green_tomato++;
			else if (box[i][j] == 1)
				q.push({ i,j });
		}
	}

	if (green_tomato == 0)
	{
		cout << 0 << '\n';
		return 0;
	}

	bfs();

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0)
			{
				cout << -1 << '\n';
				return 0;
			}

			if (ret < cnt[i][j])
				ret = cnt[i][j];
		}
	}

	cout << ret << '\n';
	return 0;
}