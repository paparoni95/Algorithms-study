#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n;
bool visited[101][101][4]; // 방향까지 방문체크

// 0:북 1:남 2:동 3:서
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,1,-1 };

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				visited[i][j][k] = (str[j] == '.') ? false : true;
			}
		}
	}
}

struct Node
{
	int x;
	int y;
	int turn;
};

// Nahwasa 풀이 참조
// 방문 체크를 그냥 해주면 안되고, 4방향으로 체크해야 한다.
// => 기존 BFS 와 달리 일직선은 모두 동일선 상으로 체크하기 때문
void bfs()
{
	queue<Node> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int turn = q.front().turn;
		q.pop();

		if (x == n - 1 && y == n - 1)
		{
			cout << turn << endl;
			return;
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			// 방향 전환을 하지 않고 쭉 가는 경로들은 모두 같은 turn 으로 해준다.
			while (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny][dir])
			{
				visited[nx][ny][dir] = true;

				q.push({ nx,ny,turn + 1 });

				nx += dx[dir];
				ny += dy[dir];
			}
		}
	}
}

void solve()
{
	input();

	bfs();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
