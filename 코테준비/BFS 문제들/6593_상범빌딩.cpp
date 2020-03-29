#include <iostream>
#include <queue>
#include <utility>
#define MAX_SIZE 31
using namespace std;

typedef struct location
{
	int z;
	int x;
	int y;
}Loc;

char a[MAX_SIZE][MAX_SIZE][MAX_SIZE];  // 상범 빌딩
int b[MAX_SIZE][MAX_SIZE][MAX_SIZE];   // 도달 횟수
bool c[MAX_SIZE][MAX_SIZE][MAX_SIZE];  // 방문 횟수
int dz[] = { 0,0,0,0,1,-1 };
int dx[] = { 0,0,-1,1,0,0 };
int dy[] = { 1,-1,0,0,0,0 };
int L, R, C, ret;                      // 변수
Loc S, E;                              // 시작, 도착위치

void initialize()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			for (int k = 0; k < MAX_SIZE; k++)
			{
				b[i][j][k] = 0;
				c[i][j][k] = false;
			}
		}
	}
}

int bfs()
{
	queue<Loc> q;
	q.push(S);
	b[S.z][S.x][S.y] = 0;
	c[S.z][S.x][S.y] = true;
	while (!q.empty())
	{
		int cz = q.front().z;
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		if (cz == E.z && cx == E.x && cy == E.y)
			return b[cz][cx][cy];

		// 현재 위치에서 이동
		for (int i = 0; i < 6; i++)
		{
			int nz = cz + dz[i];
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nz >= 0 && nz < L && nx >= 0 && nx < R && ny >= 0 && ny < C)
			{
				if (a[nz][nx][ny] != '#' && c[nz][nx][ny] == false)
				{
					c[nz][nx][ny] = true;
					b[nz][nx][ny] = b[cz][cx][cy] + 1;
					Loc node;
					node.z = nz, node.x = nx, node.y = ny;
					q.push(node);
				}
			}
		}
	}

	// 실패
	return -1;
}

void input()
{
	for (int i = 0; i < L; i++)
	{
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
			{
				//scanf("%1c", &a[i][j][k]);
				cin >> a[i][j][k];
				if (a[i][j][k] == 'S')
				{
					S.z = i;
					S.x = j;
					S.y = k;
				}

				if (a[i][j][k] == 'E')
				{
					E.z = i;
					E.x = j;
					E.y = k;
				}
			}
		}
	}
}

void output()
{
	if (ret == -1)
		printf("Trapped!\n");
	else
		printf("Escaped in %d minute(s).\n", ret);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	while (1)
	{
		scanf("%d %d %d", &L, &R, &C);
		if (L == 0 && R == 0 && C == 0) break;
		initialize();
		input();
		ret = bfs();
		output();
	}

	return 0;
}