#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 문제 접근법
// 불 문제와 비슷하다.
// 물이 먼저 1초 퍼지고 나서, 고슴도치가 1초 움직인다.

const int MAX = 51;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int R, C;
char board[MAX][MAX];

struct Pos
{
	int x, y, cnt;
};
queue<pair<int, int>> water;
queue<Pos> hedgehob;

void print()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int simulation()
{
	while (!hedgehob.empty())
	{
		// 물이 1초 (상,하,좌,우) 움직인다
		int waterSize = water.size();
		for (int i = 0; i < waterSize; i++)
		{
			int x = water.front().first;
			int y = water.front().second;
			water.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (board[nx][ny] == 'D' || board[nx][ny] == '*' || board[nx][ny] == 'X') continue;
				board[nx][ny] = '*';
				water.push({ nx,ny });
			}
		}

		// 고슴도치가 1초 (상,하,좌,우) 움직인다
		int hedgehobSize = hedgehob.size();
		for (int i = 0; i < hedgehobSize; i++)
		{
			int x = hedgehob.front().x;
			int y = hedgehob.front().y;
			int cnt = hedgehob.front().cnt;
			hedgehob.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
				if (board[nx][ny] == 'S' || board[nx][ny] == '*' || board[nx][ny] == 'X') continue;
				if (board[nx][ny] == 'D') return cnt + 1; // 탈출 성공
				board[nx][ny] = 'S';
				hedgehob.push({ nx,ny,cnt + 1 });
			}
		}
	}
	return -1; // 탈출 실패
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == '*') water.push({ i,j });
			else if (s[j] == 'S') hedgehob.push({ i,j,0 });

			board[i][j] = s[j];
		}
	}

	int ret = simulation();
	if (ret == -1)
		cout << "KAKTUS\n";
	else
		cout << ret;

	return 0;
}