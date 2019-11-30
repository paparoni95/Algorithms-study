#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[101][101];
bool visited[101][101];
int row, col;

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 1 && nx <= row && ny >= 1 && ny <= col)
			{
				if (a[nx][ny] == 1 && visited[nx][ny] == false)
				{
					visited[nx][ny] = true;
					a[nx][ny] = a[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main()
{
	/* 입력 */
	cin >> row >> col;
	for (int i = 1; i <= row; i++)
		for (int j = 1; j <= col; j++)
			scanf("%1d", &a[i][j]);

	/* 탐색 */
	bfs(1, 1);

	/* 출력 */
	cout << a[row][col];
	return 0;
}