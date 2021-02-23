#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, ans;
int field[9][9];
int copyField[9][9];
bool check[9][9];

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

vector<pair<int, int>> pos;
vector<pair<int, int>> virus;

void bfs(int i, int j)
{
	queue<pair<int, int>> q;
	q.push({ i,j });
	check[i][j] = true;
	while (!q.empty())
	{
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny]) continue;
			if (copyField[nx][ny] == 0)
			{
				copyField[nx][ny] = 2;
				check[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	freopen("input.txt", "r", stdin);

	cin >> n >> m;
	pos.reserve(n * m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 0) pos.push_back({ i,j });
			else if (field[i][j] == 2) virus.push_back({ i,j });
		}
	}

	// nxmC3
	for (int i = 0; i < pos.size(); i++)
	{
		for (int j = i + 1; j < pos.size(); j++)
		{
			for (int k = j + 1; k < pos.size(); k++)
			{
				fill(check[0], check[0] + 9 * 9, false);

				for (int a = 0; a < n; a++)
					for (int b = 0; b < m; b++)
						copyField[a][b] = field[a][b];
			
				copyField[pos[i].first][pos[i].second] = 1;
				copyField[pos[j].first][pos[j].second] = 1;
				copyField[pos[k].first][pos[k].second] = 1;

				for (int l = 0; l < virus.size(); l++)
				{
					bfs(virus[l].first, virus[l].second);
				}

				int cnt = 0;
				for (int a = 0; a < n; a++)
				{
					for (int b = 0; b < m; b++)
					{
						if (copyField[a][b] == 0) cnt++;
					}
				}
				

				ans = max(ans, cnt);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}