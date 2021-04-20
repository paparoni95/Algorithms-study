#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// 0 우, 1 하, 2 좌, 3 상
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int N, K, L;
int board[101][101];

queue<pair<int, char>> q;
deque<pair<int,int>> dq;

bool isValid(int nx, int ny)
{
	// 벽이거나
	if (nx <= 0 || ny <= 0 || nx > N || ny > N) return false;

	// 자신이면
	for (int i = 0; i < dq.size(); i++)
	{
		if (nx == dq[i].first && ny == dq[i].second)
			return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; // apple
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char d;
		cin >> x >> d;
		q.push({ x,d });
	}

	// snake move
	int dir = 0; // 0 우, 1 하, 2 좌, 3 상
	int time = 0;
	int x, nx, y, ny;
	dq.push_back({ 1,1 });
	while(1)
	{
		time++;

		x = dq.front().first;
		y = dq.front().second;

		nx = x + dx[dir];
		ny = y + dy[dir];

		// 유효 검사
		if (isValid(nx, ny) == false) break;

		if (board[nx][ny] == 1)
		{
			board[nx][ny] = 0;
			dq.push_front({ nx,ny });
		}
		else
		{
			dq.push_front({ nx,ny });
			dq.pop_back();
		}

		// 방향 전환의 시간이 왔다면
		if (!q.empty() && time == q.front().first)
		{
			if (q.front().second == 'D')
				dir = (dir + 1) % 4;
			else
				dir = (dir + 3) % 4;

			q.pop();
		}
	}

	cout << time << '\n';
	return 0;
}