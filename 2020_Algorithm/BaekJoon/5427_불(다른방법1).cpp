// 출처 : https://yabmoons.tistory.com/91
// 비슷하지만 다른 방법으로 푼 경우
// 핵심은, 불의 맵을 만들어서 퍼트리고,
// 사람이 이동을 하는데, 불의 시간 > 사람의 시간 이면 이동가능
#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

#define MAX_SIZE 1000
#define INF 99999999
using namespace std;

int w, h, tc;

int fireMap[MAX_SIZE][MAX_SIZE];
int personMap[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

pair<int, int> start;
queue<pair<int, int>> fire;

void initialize()
{
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			fireMap[i][j] = INF;
			personMap[i][j] = INF;
		}
	}
}


void bfsOne()
{
	// 불의 확장
	while (!fire.empty())
	{
		int cycle = fire.size();

		for (int i = 0; i < cycle; i++)
		{
			int cx = fire.front().first;
			int cy = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = cx + dx[j];
				int ny = cy + dy[j];

				if (nx >= 0 && ny >= 0 && nx < h && ny < w)
				{
					if (map[nx][ny] != '#')
					{
						if (fireMap[nx][ny] > fireMap[cx][cy] + 1)
						{
							fireMap[nx][ny] = fireMap[cx][cy] + 1;
							fire.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

int bfsTwo()
{
	queue<pair<pair<int, int>, int>> q; // ((x,y) , time)
	q.push({ {start.first, start.second}, 0 });
	visited[start.first][start.second] = true;

	// 사람 이동
	while (!q.empty())
	{
		int cx = q.front().first.first;
		int cy = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		// 탈출에 성공한다면?
		if (cx == h - 1 || cx == 0 || cy == w - 1 || cy == 0)
			return cnt + 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && ny >= 0 && nx < h && ny < w)
			{
				if (map[nx][ny] == '.' && visited[nx][ny] == false)
				{
					// 다음으로 이동할 구역이 불이 번지기 전이라면
					if (fireMap[nx][ny] > cnt + 1)
					{
						visited[nx][ny] = true;
						q.push({ {nx,ny}, cnt + 1 });
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
	cin >> tc;
	while (tc--)
	{
		initialize();
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == '@')
				{
					start.first = i;
					start.second = j;
				}

				if (map[i][j] == '*')
				{
					fire.push({ i,j });
					fireMap[i][j] = 0;
				}
			}
		}

		bfsOne();
		int ret = bfsTwo();
		if (ret == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout << ret << '\n';
	}

	return 0;
}
