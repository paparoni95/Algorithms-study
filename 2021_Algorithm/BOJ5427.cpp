#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// 문제 접근법
// 얼마나 빨리 빌딩을 탈출할 수 있는지? -> BFS
// 1초에 불을 먼저 이동, 그 다음에 상근이 이동

const int MAX = 1001;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
char board[MAX][MAX];
int w, h;

struct Pos
{
	int x, y, cnt;
};

void print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int simulation(queue<pair<int, int>>& fires, queue<Pos>& man)
{
	while (!man.empty()) // 상근이가 더 이상 갈 곳이 없다면, 이것은 탈출 실패
	{
		// 불 1초 이동 (상, 하, 좌, 우)
		int fireSize = fires.size();
		for (int i = 0; i < fireSize; i++)
		{
			int x = fires.front().first;
			int y = fires.front().second;
			fires.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (board[nx][ny] == '#' || board[nx][ny] == '*') continue;

				board[nx][ny] = '*';
				fires.push({ nx,ny });
			}
		}

		// 상근이 1초 이동 (상, 하, 좌, 우)
		int manSize = man.size();
		for (int i = 0; i < manSize; i++)
		{
			int x = man.front().x;
			int y = man.front().y;
			int cnt = man.front().cnt;
			man.pop();

			for (int j = 0; j < 4; j++)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) // 탈출 성공
				{
					return cnt + 1;
				}
				if (board[nx][ny] == '#' || board[nx][ny] == '*' || board[nx][ny] == '@') continue;
				board[nx][ny] = '@';
				man.push({ nx,ny,cnt + 1 });
			}
		}
	}

	return -1; // 탈출 실패
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--)
	{
		cin >> w >> h;

		queue<pair<int, int>> fires;
		queue<Pos> man;

		for (int i = 0; i < h; i++)
		{
			string s; cin >> s;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '*') fires.push({ i,j });
				else if (s[j] == '@') man.push({ i,j,0 });

				board[i][j] = s[j];
			}
		}

		int ret = simulation(fires, man);
		if (ret == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ret << '\n';
	}

	return 0;
}