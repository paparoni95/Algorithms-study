#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct Pos
{
	int z, x, y;
};
const int MAX = 101;
const int dz[] = { 0,0,0,0,1,-1 };
const int dx[] = { 0,0,1,-1,0,0 };
const int dy[] = { 1,-1,0,0,0,0 };

int board[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int M, N, H; // 가로, 세로, 높이

queue<Pos> q;

void print()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cout << board[i][j][k];
			}
			cout << endl;
		}
		cout << endl;
	}
}

void BFS() // 토마토 익히기
{
	while (!q.empty())
	{
		int cz = q.front().z;
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = cz + dz[i];
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nz < 0 || nx < 0 || ny < 0 || nz >= H || nx >= N || ny >= M) continue;
			if (board[nz][nx][ny] != 0 || visit[nz][nx][ny]) continue;

			visit[nz][nx][ny] = true;
			board[nz][nx][ny] = board[cz][cx][cy] + 1;
			q.push({ nz,nx,ny });
		}
	}
}

bool checkTomato() // 토마토가 모두 익었다면 true, 아니면 false
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (!board[i][j][k] && !visit[i][j][k])
					return false;
			}
		}
	}
	return true;
}

int calculateTomato() // 토마토가 모두 익을 때까지 며칠 걸리는지 반환
{
	int day = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				day = max(day, board[i][j][k]);
			}
		}
	}

	return day;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> M >> N >> H;
	bool check = false;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> board[i][j][k];

				if (board[i][j][k] == 1)
				{
					q.push({ i,j,k, });
					board[i][j][k] = 0;
					visit[i][j][k] = true;
				}
					
				else if (!board[i][j][k])
					check = true;
			}
		}
	}

	// 토마토가 처음부터 모두 익었다면
	if (!check)
		cout << 0;
	else
	{
		BFS();
		if (checkTomato())
			cout << calculateTomato();
		else
			cout << -1;
	}
		
	return 0;
}