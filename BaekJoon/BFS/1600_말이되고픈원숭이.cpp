#include <iostream>
#include <queue>
using namespace std;

int a[201][201];
bool visited[201][201][31];
int monkey_dx[] = { 0,0,-1,1 };
int monkey_dy[] = { 1,-1,0,0 };
int horse_dx[] = { -2,-1,-2,-1,1,2,1,2 };
int horse_dy[] = { -1,-2,1,2,-2,-1,2,1 };
int k, w, h;

struct state
{
	int x;
	int y;
	int move_cnt;
	int use_ability;
};

int bfs(int x, int y)
{
	queue<state> q;
	state temp;
	temp.x = 0, temp.y = 0, temp.move_cnt = 0, temp.use_ability = 0;
	q.push(temp);

	while (!q.empty())
	{
		temp = q.front();
		int cx = temp.x;
		int cy = temp.y;
		int c_move_cnt = temp.move_cnt;
		int c_use_ability = temp.use_ability;
		q.pop();

		// 원숭이가 도착지점에 왔다면 값을 리턴해준다.
		if (cx == h - 1 && cy == w - 1)
		{
			return c_move_cnt;
		}

		// 말의 능력을 사용할 잔여량이 남아있다면
		if (c_use_ability < k)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = cx + horse_dx[i];
				int ny = cy + horse_dy[i];
				if (nx >= 0 && nx < h && ny >= 0 && ny < w)
				{
					if (a[nx][ny] == 0 && visited[nx][ny][c_use_ability + 1] == false)
					{
						visited[nx][ny][c_use_ability + 1] = true;
						temp.x = nx, temp.y = ny, temp.move_cnt = c_move_cnt + 1;
						temp.use_ability = c_use_ability + 1;
						q.push(temp);
					}
				}
			}
		}

		// 기존의 원숭이는 상하좌우로 움직일 수 있으므로
		for (int i = 0; i < 4; i++)
		{
			int nx = cx + monkey_dx[i];
			int ny = cy + monkey_dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w)
			{
				if (a[nx][ny] == 0 && visited[nx][ny][c_use_ability] == false)
				{
					visited[nx][ny][c_use_ability] = true;
					temp.x = nx, temp.y = ny, temp.move_cnt = c_move_cnt + 1;
					temp.use_ability = c_use_ability;
					q.push(temp);
				}
			}
		}
	}

	// 갈 수 없는 경우
	return -1;
}

int main()
{
	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> a[i][j];

	int ans = bfs(0, 0);
	cout << ans;
	return 0;
}