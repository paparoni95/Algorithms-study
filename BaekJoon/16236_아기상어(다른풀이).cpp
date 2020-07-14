#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

struct Shark
{
	int x, y, shark_size, shark_eat, time;
};

struct Fish
{
	int x, y, dist;
};

int N;
int stage[20][20];

Shark shark;
vector<Fish> fish;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

bool Standard(Fish& a, Fish& b)
{
	// 가장 가까운 -> 가장 위에  -> 가장 왼쪽에
	if (a.dist <= b.dist)
	{
		if (a.dist == b.dist)
		{
			if (a.x <= b.x)
			{
				if (a.x == b.x)
				{
					if (a.y < b.y)
					{
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

// 아기 상어가 BFS로 탐색하면서 잡아 먹을 수 있는 물고기들을 전부 집어넣는다.
void FindEatFish()
{
	bool visited[20][20] = { false, };
	queue<tuple<int, int, int>> q; // (x, y, size)
	visited[shark.x][shark.y] = true;
	q.push({ shark.x, shark.y, 0 });

	while (!q.empty())
	{
		int cx = get<0>(q.front());
		int cy = get<1>(q.front());
		int time = get<2>(q.front());
		q.pop();


		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];

			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (visited[nx][ny] == true) continue;

			// 빈 공간이면 그냥 지나간다.
			if (stage[nx][ny] == 0)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny, time + 1 });
			}
			// 작은 물고기는 상어가 먹을 수 있다.
			else if (stage[nx][ny] < shark.shark_size && stage[nx][ny] != 0)
			{
				fish.push_back({ nx,ny,time + 1 });
				visited[nx][ny] = true;
				q.push({ nx,ny, time + 1 });
			}
			// 물고기와 아기 상어의 크기가 같으면 먹을 수는 없지만 지나간다.
			else if (stage[nx][ny] == shark.shark_size && stage[nx][ny] != 0)
			{
				visited[nx][ny] = true;
				q.push({ nx,ny, time + 1 });
			}
		}
	}
}

void Simulation()
{
	while (1)
	{
		fish.clear(); // 물고기 초기화.

		FindEatFish(); // 먹을 수 있는 물고기 리스트 구하기.

		if (fish.size() == 0)
		{
			cout << shark.time;
			break;
		}
		else if (fish.size() == 1) // 먹을 수 있는 물고기가 1마리라면 그냥 먹는다.
		{
			stage[fish[0].x][fish[0].y] = 9;
			stage[shark.x][shark.y] = 0;
			shark.x = fish[0].x, shark.y = fish[0].y;
			shark.shark_eat++;
			shark.time += fish[0].dist; // 누적 합

			if (shark.shark_eat == shark.shark_size)
			{
				shark.shark_size++;
				shark.shark_eat = 0;
			}
		}
		else // 그 이상의 물고기라면, 가장 가까운 물고기를 먹어야 한다.
		{
			sort(fish.begin(), fish.end(), Standard);
			stage[fish[0].x][fish[0].y] = 9;
			stage[shark.x][shark.y] = 0;
			shark.x = fish[0].x, shark.y = fish[0].y;
			shark.shark_eat++;
			shark.time += fish[0].dist;

			if (shark.shark_eat == shark.shark_size)
			{
				shark.shark_size++;
				shark.shark_eat = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> stage[i][j];
			if (stage[i][j] == 9)
			{
				shark = { i,j,2,0,0 };
			}
		}
	}

	Simulation(); // 상어가 사냥을 시작한다.

	return 0;
}