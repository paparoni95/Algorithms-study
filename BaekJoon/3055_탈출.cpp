#include <iostream>
#include <queue>
#include <vector>

#define MAX_SIZE 51
using namespace std;

int R, C;
bool visited[MAX_SIZE][MAX_SIZE];
char a[MAX_SIZE][MAX_SIZE];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> waters;
pair<int, int> start;
pair<int, int> finish;

void show()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int bfs()
{
	queue<pair<int, int>> water_q;
	for (int i = 0; i < waters.size(); i++)
		water_q.push({ waters[i].first, waters[i].second });

	queue<pair<int, int>> q;
	q.push({ start.first, start.second });
	visited[start.first][start.second] = true;

	int time = 0;
	while (!q.empty())
	{
		int water_size = water_q.size();
		for (int i = 0; i < water_size; i++)
		{
			int cx = water_q.front().first;
			int cy = water_q.front().second;
			water_q.pop();

			for (int k = 0; k < 4; k++)
			{
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < R && ny < C)
				{
					if (a[nx][ny] == '.' || a[nx][ny] == 'S')
					{
						a[nx][ny] = '*';
						water_q.push({ nx,ny });
					}
				}
			}
		}

		int q_size = q.size();
		for (int i = 0; i < q_size; i++)
		{
			int cx = q.front().first;
			int cy = q.front().second;
			q.pop();

			if (finish.first == cx && finish.second == cy)
				return time;

			for (int k = 0; k < 4; k++)
			{
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx >= 0 && ny >= 0 && nx < R && ny < C)
				{
					if (a[nx][ny] != 'X' && a[nx][ny] != '*' && !visited[nx][ny])
					{
						visited[nx][ny] = true;
						q.push({ nx,ny });
					}
				}
			}
		}

		time++;
	}

	return -1;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'S')
				start = { i,j };
			if (a[i][j] == 'D')
				finish = { i,j };
			if (a[i][j] == '*')
				waters.push_back({ i,j });
		}
	}

	int ret = bfs();
	//show();
	if (ret == -1)
		cout << "KAKTUS" << '\n';
	else
		cout << ret << '\n';
	return 0;
}