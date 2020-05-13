// https://yabmoons.tistory.com/41
// 하나하나 세세한 구현도 좋지만, 생략할 수 있는 부분은 생략을 해서 문제를 간소화 시키는 것도 중요하다.
// 다음에 다시 풀어보자.
#include <iostream>

#define MAX 50
using namespace std;

int N, M;
int a[MAX][MAX];
bool visit[MAX][MAX];

struct Robot
{
	int x, y, d;
};

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int turn_Direction(int d)
{
	if (d == 0) return 3;
	else if (d == 1) return 0;
	else if (d == 2) return 1;
	else if (d == 3) return 2;
}

void simulation(Robot robot)
{
	int x = robot.x;
	int y = robot.y;
	int d = robot.d;
	int room = 0;
	a[x][y] = 2;
	room++;

	int nx, ny, nd;
	while (1)
	{
		int temp_d = d;
		bool can_clean = false;
		int can_not_clean = 0;

		// 왼쪽방향으로부터 4방향 차례대로 탐색
		for (int i = 0; i < 4; i++)
		{
			nd = turn_Direction(d);
			nx = x + dx[nd];
			ny = y + dy[nd];

			// 청소를 할 수 있다면? 청소하자.
			if (a[nx][ny] == 0)
			{
				can_clean = true;
				break;
			}

			// 벽이거나, 청소를 했거나, 범위를 벗어난 경우
			else if (a[nx][ny] == 1 || a[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= N || ny >= M))
			{
				d = nd;
				can_not_clean++;
			}
		}
		
		// 청소하기.
		if (can_clean == true)
		{
			a[nx][ny] = 2;
			room++;
			d = nd;
		}

		if (can_not_clean == 4)
		{
			// 후진한다.
			nx = x - dx[temp_d];
			ny = y - dy[temp_d];
			d = temp_d;
			// 범위 밖이거나, 벽인 경우 작동 종료.
			if ((nx < 0 || ny < 0 || nx >= N || ny >= M) || a[nx][ny] == 1) break;
		}

		x = nx;
		y = ny;
	}

	cout << room << endl;
}

int main()
{
	Robot robot;
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	cin >> robot.x >> robot.y >> robot.d;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	simulation(robot);
	return 0;
}