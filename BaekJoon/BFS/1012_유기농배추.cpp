#include <iostream>
#include <queue>
using namespace std;

int a[50][50];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int row, column, K, tc;
int ans;

void initialize()
{
	ans = 0;
	for (int i = 0; i < 50; i++)
		for (int j = 0; j < 50; j++)
			a[i][j] = 0;
}

void bfs(int x, int y)
{
	ans++; // 지렁이하나 추가
	queue<pair<int, int>> tq;
	tq.push({ x,y });
	a[x][y] = 0;

	while (!tq.empty())
	{
		int cur_x = tq.front().first;
		int cur_y = tq.front().second;
		tq.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int next_x = cur_x + dx[dir];
			int next_y = cur_y + dy[dir];
			// 경계 체크
			if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < column)
			{
				if (a[next_x][next_y])
				{
					a[next_x][next_y] = 0;
					tq.push({ next_x, next_y });
				}
			}
		}
	}
}

int main()
{
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		initialize();
		queue<pair<int, int>> q; // 배추 좌표 저장
		cin >> column >> row >> K;

		for (int j = 0; j < K; j++)
		{
			int x, y;
			cin >> y >> x;
			a[x][y] = 1;
			q.push({ x, y });
		}

		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			int find_x = q.front().first;
			int find_y = q.front().second;
			q.pop();
			if (a[find_x][find_y])
			{
				bfs(find_x, find_y);
			}
		}

		cout << ans << '\n';
	}
	return 0;
}