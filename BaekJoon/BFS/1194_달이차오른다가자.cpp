#include <iostream>
#include <queue>
using namespace std;

char a[51][51];
bool visited[51][51][64];
int n, m;
int start_x, start_y;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct state
{
	int x;
	int y;
	int cnt;
	int key;
};

bool KeyCheck(int cur_key, char door)
{
	int check = cur_key & (1 << (int(door - 'A')));
	if (check == 0)
		return false;
	else
		return true;
}

int BFS(int x, int y)
{
	queue<state> q;
	state temp;
	temp.x = x, temp.y = y, temp.cnt = 0, temp.key = 0;
	q.push(temp);
	visited[x][y][0] = true;

	while (!q.empty())
	{
		temp = q.front();
		int cx = temp.x;
		int cy = temp.y;
		int cnt = temp.cnt;
		int key = temp.key;
		q.pop();

		if (a[cx][cy] == '1')
			return cnt;

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (visited[nx][ny][key] == false)
				{
					if (a[nx][ny] == '.' || a[nx][ny] == '1')
					{
						visited[nx][ny][key] = true;
						temp.x = nx, temp.y = ny;
						temp.cnt = cnt + 1, temp.key = key;
						q.push(temp);
					}
					else if (a[nx][ny] >= 'a' && a[nx][ny] <= 'f')
					{
						int newKey = key | (1 << (int(a[nx][ny] - 'a')));
						visited[nx][ny][newKey] = true;
						temp.x = nx, temp.y = ny;
						temp.cnt = cnt + 1, temp.key = newKey;
						q.push(temp);
					}
					else if (a[nx][ny] >= 'A' && a[nx][ny] <= 'F')
					{
						if (KeyCheck(key, a[nx][ny]))
						{
							visited[nx][ny][key] = true;
							temp.x = nx, temp.y = ny;
							temp.cnt = cnt + 1, temp.key = key;
							q.push(temp);
						}
					}
				}
			}
		}
	}
	// 결국에는 탈출하지 못하는 경우
	return -1;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '0')
			{
				start_x = i;
				start_y = j;
				a[i][j] = '.';
			}
		}
	}

	int ans = BFS(start_x, start_y);
	cout << ans;
	return 0;
}