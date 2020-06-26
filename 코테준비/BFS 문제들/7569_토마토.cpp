#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int dx[] = { 0,0,1,-1,0,0 };
const int dy[] = { 1,-1,0,0,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

struct Tomato
{
	int z, x, y;
};

int M, N, H, not_tomato;
int stage[MAX][MAX][MAX];

queue<Tomato> q;

void BFS(queue<Tomato>& q)
{
	while (!q.empty())
	{
		Tomato tomato = q.front();
		q.pop();

		for (int d = 0; d < 6; d++)
		{
			int nz = tomato.z + dz[d];
			int nx = tomato.x + dx[d];
			int ny = tomato.y + dy[d];

			if (nz < 0 || nz >= H) continue;
			if (nx < 0 || nx >= N) continue;
			if (ny < 0 || ny >= M) continue;
			if (stage[nz][nx][ny] == 0)
			{
				not_tomato--;
				stage[nz][nx][ny] = stage[tomato.z][tomato.x][tomato.y] + 1;
				q.push({ nz,nx,ny });
			}
		}
	}
}

int DateCalculator()
{
	int day = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				day = max(day, stage[i][j][k]);
			}
		}
	}

	return day;
}

void Solution(queue<Tomato>& q)
{
	int day = 0;

	// 토마토 전이
	BFS(q);

	// 모든 토마토가 다 익었다면?, 걸린 횟수는?
	if (not_tomato == 0)
	{
		day = DateCalculator();
		cout << day - 1;
	}
	// 익지 않은 토마토가 있다면?, 이는 실패.
	else
	{
		cout << -1;
	}

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> stage[i][j][k];
				if (stage[i][j][k] == 0)      not_tomato++;     // 익지 않은
				else if (stage[i][j][k] == 1) q.push({ i,j,k });
			}
		}
	}

	if (not_tomato == 0)
	{
		cout << 0;
	}
	else
	{
		Solution(q);
	}

	return 0;
}