#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, K, L;
int a[101][101];
const int dx[] = { 0,0,1,-1 }; // 우, 좌, 상, 
const int dy[] = { 1,-1,0,0 };

vector<pair<int, char>> v;

void input()
{
	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x - 1][y - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x;
		char d;
		cin >> x >> d;
		v.push_back({ x,d });
	}
}

int nextDirection(int d, char c)
{
	if (c == 'L')
	{
		if (d == 0) return 3;
		else if (d == 1) return 2;
		else if (d == 2) return 0;
		else if (d == 3) return 1;
	}
	else if (c == 'D')
	{
		if (d == 0) return 2;
		else if (d == 1) return 3;
		else if (d == 2) return 1;
		else if (d == 3) return 0;
	}
}

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void solve()
{
	input();

	deque<pair<int, int>> dq;
	int x = 0;
	int y = 0;
	int d = 0;
	int t = 0;
	int idx = 0;
	dq.push_back({ x,y });
	a[x][y] = 2;

	while (1)
	{
		t++;

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || a[nx][ny] == 2) break;
		else if (a[nx][ny] == 0)
		{
			a[nx][ny] = 2;
			a[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
			dq.push_front({ nx,ny });
		}
		else if (a[nx][ny] == 1)
		{
			a[nx][ny] = 2;
			dq.push_front({ nx,ny });
		}

		if (idx < v.size())
		{
			if (t == v[idx].first)
			{
				if (v[idx].second == 'L') d = nextDirection(d, 'L');
				else if (v[idx].second == 'D') d = nextDirection(d, 'D');
				idx++;
			}
		}

		x = nx;
		y = ny;
	}

	cout << t << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
