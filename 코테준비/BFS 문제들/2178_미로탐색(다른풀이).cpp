#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

int N, M;
int stage[MAX][MAX];

// visited 배열을 추가하니까, 메모리 초과 발생!
// 그래서, stage로 길을 확인하면서, 동시에 방문 여부도 체크로 해결.

struct Node
{
	int x, y, cnt;
};

int FindExit(int x, int y)
{
	queue<Node> q;
	q.push({ x,y,1 });
	stage[x][y] = 0;

	while (!q.empty())
	{
		Node cur = q.front();
		q.pop();

		if (cur.x == N - 1 && cur.y == M - 1)
		{
			return cur.cnt;
		}

		for (int d = 0; d < 4; d++)
		{
			int nx = cur.x + dx[d];
			int ny = cur.y + dy[d];

			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (stage[nx][ny])
				{
					stage[nx][ny] = 0;
					q.push({ nx,ny, cur.cnt + 1 });
				}
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &stage[i][j]);
		}
	}

	int ans = FindExit(0, 0);
	printf("%d\n", ans);
	return 0;
}