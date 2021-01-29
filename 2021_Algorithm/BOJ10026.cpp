#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 문제 접근법
// 정상인 눈에서 BFS
// 비정상인 눈에서는 R == G와 같게 보면서 BFS 돌린다.

const int MAX = 101;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int N, ans1, ans2;
char a[MAX][MAX];
char b[MAX][MAX];

void lookPerson(int x, int y, char focus)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	a[x][y] = '.';
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (a[nx][ny] == focus)
			{
				a[nx][ny] = '.';
				q.push({ nx,ny });
			}
		}
	}
}

void lookSickPerson(int x, int y, char focus)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	b[x][y] = '.';
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if ((focus == 'R' || focus == 'G') && (b[nx][ny] == 'R' || b[nx][ny] == 'G'))
			{
				b[nx][ny] = '.';
				q.push({ nx,ny });
			}
			else if (b[nx][ny] == focus)
			{
				b[nx][ny] = '.';
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			a[i][j] = s[j];
			b[i][j] = s[j];
		}
	}

	for (int i = 0; i < N; i++) // 정상인 눈에서 보면
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] != '.')
			{
				lookPerson(i, j, a[i][j]);
				ans1++;
			}
		}
	}

	for (int i = 0; i < N; i++) // 비정상인 눈에서 보면
	{
		for (int j = 0; j < N; j++)
		{
			if (b[i][j] != '.')
			{
				lookSickPerson(i, j, b[i][j]);
				ans2++;
			}
		}
	}

	cout << ans1 << ' ' << ans2;
	return 0;
}