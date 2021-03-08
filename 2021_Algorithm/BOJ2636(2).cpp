#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 101;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int r, c;
int a[MAX][MAX], b[MAX][MAX];
vector<pair<int, int>> air;
queue<pair<int, int>> nq; // 관점 : 바깥쪽 치즈와 접촉된 외부 공기

void input()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
			{
				b[i][j] = -1; // 치즈가 있는 곳은 -1
			}
		}
	}
}

void divideAir()
{
	// 외부 공기와 내부 공기를 구분하기
	// 외부 공기 1, 내부 공기 0
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	b[0][0] = 1;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (a[nx][ny] == 0 && b[nx][ny] == 0)
			{
				b[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void selectCheeze()
{
	// 외부 공기와 접촉된 바깥 치즈들을 넣어준다.
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (b[i][j] == 1)
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (a[nx][ny] == 1)
					{
						nq.push({ i,j });
						break;
					}
				}
			}
		}
	}
}

void meltCheeze()
{
	queue<pair<int, int>> q = nq;
	while (!nq.empty()) nq.pop();
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (a[nx][ny] == 1)
			{
				a[nx][ny] = 0;
				nq.push({ nx,ny });
			}
		}
	}
}

void updateAir()
{
	// 외부 공기와 접촉한 내부 공기를 합치는 과정
	// 내부 공기를 만나면 이 역시 외부 공기와 같은 역할을 하므로 nq에 넣어준다.
	queue<pair<int, int>> q = nq;
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
			if (b[nx][ny] == 0)
			{
				b[nx][ny] = 1;
				q.push({ nx,ny });
				nq.push({ nx,ny });
			}
		}
	}
}

bool check()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] == 1) return false;
		}
	}
	return true;
}

void solve()
{
	input();
	divideAir();
	selectCheeze();

	int t = 0, finalSize = 0;
	while (1)
	{
		if (check()) break;
		meltCheeze();
		finalSize = nq.size();
		updateAir();
		t++;
	}

	cout << t << '\n';
	cout << finalSize << '\n';
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

	return 0;
}