#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_SIZE 50 + 1
using namespace std;

int T, M, N, K;
int a[MAX_SIZE][MAX_SIZE];
bool c[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfs(int x, int y)
{
	c[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M)
		{
			if (!c[nx][ny] && a[nx][ny] == 1)
			{
				dfs(nx, ny);
			}
		}
	}
}

void initialize()
{
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			a[i][j] = 0;
			c[i][j] = false;
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> T;
	while (T--)
	{
		//fill(&c[0][0], &c[MAX_SIZE][MAX_SIZE], 0);
		//fill(&a[0][0], &a[MAX_SIZE][MAX_SIZE], 0);
		initialize();

		int cnt = 0; //  배추 흰지렁이 수
		vector<pair<int, int>> pos;

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int col, row;
			cin >> col >> row;
			a[row][col] = 1;
			pos.push_back({ row,col });
		}

		for (int i = 0; i < pos.size(); i++)
		{
			int x = pos[i].first;
			int y = pos[i].second;
			if (!c[x][y] && a[x][y] == 1)
			{
				cnt++;
				dfs(x, y);
			}
		}

		cout << cnt << '\n'; // 개행을 넣어줘야 AC를 받을 수 있다.
	}
	return 0;
}
