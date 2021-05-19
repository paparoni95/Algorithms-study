#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int N;
int stage[MAX][MAX];
bool visited[MAX][MAX];

void FindSafetyZone(int x, int y)
{
	visited[x][y] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (visited[nx][ny] == false)
			{
				FindSafetyZone(nx, ny);
			}
		}
	}
}

void Rainning(int rain)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (stage[i][j] <= rain)
			{
				visited[i][j] = true;
			}
		}
	}
}

void Solution(int max_height)
{
	int ans = 0, safy_zone_cnt = 0;

	// 1 ~ max_height, 비를 내려서 안전 지대 체크
	for (int h = 0; h <= max_height; h++)
	{
		safy_zone_cnt = 0;
		memset(visited, false, sizeof(visited));

		Rainning(h); // 비 내리고,

		for (int i = 0; i < N; i++) // 안전 지역 찾기.
		{
			for (int j = 0; j < N; j++)
			{
				if (!visited[i][j])
				{
					safy_zone_cnt++;
					FindSafetyZone(i, j);
				}
			}
		}

		ans = max(ans, safy_zone_cnt);
	}

	cout << ans;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> N;

	int max_height = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> stage[i][j];
			if (stage[i][j] > max_height)
			{
				max_height = stage[i][j];
			}
		}
	}

	Solution(max_height);
	return 0;
}