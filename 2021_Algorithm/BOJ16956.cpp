#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 문제 접근법
// 단순히 늑대의 상하좌우를 울타리로 가뒀을 때,
// 그래도 양이 먹힌다면 틀린거고 아니면 산 것이다.

int R, C;
char board[501][501];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

vector<pair<int, int>> pos;

bool findSheep(int x, int y)
{
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && ny >= 0 && nx < R && ny < C)
		{
			if (board[nx][ny] == 'S')
				return true;
			else if(board[nx][ny] == '.')
				board[nx][ny] = 'D';
		}
	}

	return false;
}

void printMap()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << board[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			board[i][j] = s[j];
			if (s[j] == 'W')
				pos.push_back({ i,j });
		}
	}
	for (int i = 0; i < pos.size(); i++)
	{
		if (findSheep(pos[i].first, pos[i].second))
		{
			cout << 0;
			return 0;
		}
	}

	cout << 1 << '\n';
	printMap();
	return 0;
}