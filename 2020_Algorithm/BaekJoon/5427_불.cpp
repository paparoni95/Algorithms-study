#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX_SIZE 1001
using namespace std;

char a[MAX_SIZE][MAX_SIZE];       // 빌딩 상태
int fireSec[MAX_SIZE][MAX_SIZE];  // 불
int moveSec[MAX_SIZE][MAX_SIZE];  // 사람
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int start_x, start_y;
int tc, w, h;

void show()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%d ", fireSec[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			printf("%d ", moveSec[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool isExit(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= h) return true;
		if (ny < 0 || ny >= w) return true;
	}
	return false;
}

void bfs1(vector<pair<int, int>>& fire)
{
	queue<pair<int, int>> q;
	for (int i = 0; i < fire.size(); i++)
	{
		int x = fire[i].first;
		int y = fire[i].second;
		q.push({ x,y });
		fireSec[x][y] = 1;
	}
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w)
			{
				if (a[nx][ny] != '#' && fireSec[nx][ny] == -1)
				{
					fireSec[nx][ny] = fireSec[cx][cy] + 1;
					q.push({ nx,ny });
				}
			}
		}
	}
}

int bfs2()
{
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	moveSec[start_x][start_y] = 1;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		// 빌딩에서 탈출할 수 있다면?
		if (isExit(cx, cy)) return moveSec[cx][cy];

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w)
			{
				if (a[nx][ny] == '.' && moveSec[nx][ny] == -1)
				{
					// 불이 퍼진 시간보다 사람이 더 빠른 경우
					if (fireSec[nx][ny] > moveSec[cx][cy] + 1)
					{
						moveSec[nx][ny] = moveSec[cx][cy] + 1;
						q.push({ nx,ny });
					}

					// 애초에 불이 번지지 않은 곳이면
					else if (fireSec[nx][ny] == -1)
					{
						moveSec[nx][ny] = moveSec[cx][cy] + 1;
						q.push({ nx,ny });
					}
				}
			}
		}
	}

	return -1; // 탈출 실패
}

int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &w, &h);
		memset(fireSec, -1, sizeof(fireSec));
		memset(moveSec, -1, sizeof(moveSec));
		vector<pair<int, int>> fire;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@')
				{
					start_x = i, start_y = j;
				}
				if (a[i][j] == '*')
					fire.push_back({ i,j });
			}
		}
		bfs1(fire);
		int ret = bfs2();
		//show();

		if (ret == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", ret);
	}

	return 0;
}