// https://yabmoons.tistory.com/229

// 굳이 다 돌릴필요 없이, 구슬이 동쪽으로 갔으면, 다시 서쪽으로 갈 필요가 없다.
// 또, 문제에서 제시한 'O' 부분은 복사해서 넣자. 이것때문에 고생많이함..
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 10;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };


int N, M, ans = 987654321;
char stage[MAX][MAX];

pair<int, int> Red, Blue;

int MoveDist(int x, int y, int xx, int yy)
{
	return abs(x - xx) + abs(y - yy);
}

int InverseDirection(int cur_d)
{
	if (cur_d == 0) return 1;
	else if (cur_d == 1) return 0;
	else if (cur_d == 2) return 3;
	else if (cur_d == 3) return 2;
}

void Move(int Rx, int Ry, int Bx, int By, int cnt, int dir)
{
	if (cnt >= ans) return;
	if (cnt > 10) return;

	bool red_flag = false;
	bool blue_flag = false;

	int nRx = Rx + dx[dir];
	int nRy = Ry + dy[dir];
	while (1)
	{
		if (stage[nRx][nRy] == '#') break;
		if (stage[nRx][nRy] == 'O')
		{
			red_flag = true;
			break;
		}
		nRx = nRx + dx[dir];
		nRy = nRy + dy[dir];
	}
	nRx = nRx - dx[dir];
	nRy = nRy - dy[dir];

	int nBx = Bx + dx[dir];
	int nBy = By + dy[dir];
	while (1)
	{
		if (stage[nBx][nBy] == '#') break;
		if (stage[nBx][nBy] == 'O')
		{
			blue_flag = true;
			break;
		}

		nBx = nBx + dx[dir];
		nBy = nBy + dy[dir];
	}
	nBx = nBx - dx[dir];
	nBy = nBy - dy[dir];

	if (blue_flag == true) return;
	else
	{
		if (red_flag == true)
		{
			ans = min(ans, cnt);
			return;
		}
	}

	if (nRx == nBx && nRy == nBy)
	{
		int red_dist = MoveDist(Rx, Ry, nRx, nRy);
		int blue_dist = MoveDist(Bx, By, nBx, nBy);

		if (red_dist > blue_dist)
		{
			nRx = nRx - dx[dir];
			nRy = nRy - dy[dir];
		}
		else
		{
			nBx = nBx - dx[dir];
			nBy = nBy - dy[dir];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == dir) continue;
		if (i == InverseDirection(dir)) continue;

		Move(nRx, nRy, nBx, nBy, cnt + 1, i);
	}
}

void Simulation()
{
	for (int i = 0; i < 4; i++)
	{
		int x = Red.first;
		int y = Red.second;
		int xx = Blue.first;
		int yy = Blue.second;

		Move(x, y, xx, yy, 1, i);
	}

	if (ans > 10 || ans == 987654321) ans = -1;
	cout << ans << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> stage[i][j];
			if (stage[i][j] == 'R')
			{
				Red = { i,j };
				stage[i][j] = '.';
			}
			else if (stage[i][j] == 'B')
			{
				Blue = { i,j };
				stage[i][j] = '.';
			}
		}
	}

	Simulation();
	return 0;
}
