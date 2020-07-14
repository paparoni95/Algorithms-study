// https://yabmoons.tistory.com/36
// 주사위를 배열 하나로만 표현할 수 있다.
#include <iostream>
#include <vector>
using namespace std;

int N, M, Sx, Sy, K;
int a[21][21];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

/*
dice의 평면도

  2
4 1 3
  5
  6

*/
int dice[7];
vector<int> cmd;

void rollTheDice(int d)
{
	int d1, d2, d3, d4, d5, d6;
	d1 = dice[1], d2 = dice[2], d3 = dice[3];
	d4 = dice[4], d5 = dice[5], d6 = dice[6];

	if (d == 0)
	{
		dice[1] = d4;
		dice[4] = d6;
		dice[6] = d3;
		dice[3] = d1;
	}
	else if (d == 1)
	{
		dice[1] = d3;
		dice[4] = d1;
		dice[6] = d4;
		dice[3] = d6;
	}
	else if (d == 2)
	{
		dice[2] = d1;
		dice[6] = d2;
		dice[5] = d6;
		dice[1] = d5;
	}
	else if (d == 3)
	{
		dice[1] = d2;
		dice[5] = d1;
		dice[6] = d5;
		dice[2] = d6;
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> Sx >> Sy >> K;
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++) 
		{
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int temp; cin >> temp;
		cmd.push_back(temp - 1);
	}

	int x = Sx;
	int y = Sy;

	// simulation
	for (int i = 0; i < cmd.size(); i++)
	{
		int nx = x + dx[cmd.at(i)];
		int ny = y + dy[cmd.at(i)];
		int d = cmd.at(i);

		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

		// 주사위를 굴린다
		rollTheDice(d);
		if (a[nx][ny] == 0) a[nx][ny] = dice[6];
		else
		{
			dice[6] = a[nx][ny];
			a[nx][ny] = 0;
		}

		cout << dice[1] << '\n';

		x = nx;
		y = ny;
	}

	return 0;
}