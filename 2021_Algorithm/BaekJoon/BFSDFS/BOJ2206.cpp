#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1000;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int n, m;
int board[MAX][MAX];
bool vis[MAX][MAX][2]; // 방문한 정점이라도, 벽을 부수고 왔는지, 아닌지에 따라 서로 다른 경로이므로

class Node
{
public:
	int x;
	int y;
	int cost;
	int skill;

	Node(int x, int y, int cost, int skill)
		:x(x), y(y), cost(cost), skill(skill) {}
};

void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); ++j)
		{
			board[i][j] = str[j] - '0';
		}
	}
}

void bfs()
{
	queue<Node> q;
	q.push(Node(0, 0, 1, 0)); // (x,y,cost,skill)
	vis[0][0][0] = true;

	
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		if (node.x == n - 1 && node.y == m - 1)
		{
			cout << node.cost << '\n';
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = node.x + dx[i];
			int ny = node.y + dy[i];
			
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 벽을 하나까지 부실 수 있다.
			if (board[nx][ny] == 1 && node.skill == 0)
			{
				vis[nx][ny][node.skill + 1] = true;
				q.push(Node(nx, ny, node.cost + 1, node.skill + 1));
			}
			else if (board[nx][ny] == 0 && vis[nx][ny][node.skill] == false)
			{
				vis[nx][ny][node.skill] = true;
				q.push(Node(nx, ny, node.cost + 1, node.skill));
			}
		}
	}

	cout << -1 << '\n';
	return;
}

void solution()
{
	input();
	bfs();
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	solution();

	return 0;
}