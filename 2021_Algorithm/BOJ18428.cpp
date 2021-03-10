#include <iostream>
#include <vector>
using namespace std;

int n;
bool ok;
char a[7][7];
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> teachers;

void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'T')
				teachers.push_back({ i,j });
		}
	}
}

bool check()
{
	for (int t = 0; t < teachers.size(); t++)
	{
		int x = teachers[t].first;
		int y = teachers[t].second;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			while (1)
			{
				if (nx < 1 || ny < 1 || nx > n || ny > n) break;
				if (a[nx][ny] == 'O') break;
				if (a[nx][ny] == 'S') return false;
				nx = nx + dx[i];
				ny = ny + dy[i];
			}
		}
	}

	return true;
}

void dfs(int cnt)
{
	if (cnt == 3)
	{
		if (check()) ok = true;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == 'X')
			{
				a[i][j] = 'O';
				dfs(cnt + 1);
				a[i][j] = 'X';
			}
		}
	}
}

void solve()
{
	input();
	dfs(0);
	if (ok) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	solve();
	return 0;
}