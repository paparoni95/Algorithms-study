#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 101;
const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

int a[MAX][MAX]; // 원본 맵
int b[MAX][MAX];

int r, c, time, finalSize;
queue<pair<int, int>> nextQ;

void show()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void divideAir() // 외부 공기 1, 내부 공기 0으로 구분시키기
{
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
			if (a[nx][ny] == 0 && b[nx][ny] == 0) // 치즈가 아니면서 공기인 경우
			{
				b[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

void findCheeseAir() // 외부 공기 중에서도, 치즈와 인접한 공기 찾기
{
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
						nextQ.push({ i,j });
						break;
					}
				}
			}
		}
	}
}

void meltCheese()
{
	// nextQ에 값들을 복사하고 비워줌.
	// 치즈가 있는 좌표는 치즈를 녹여주고, 해당 치즈의 좌표를 nextQ에 넣어줌.
	// 녹인 부분이 다음 치즈를 녹일 수 있는 외부 공기이기 때문
	queue<pair<int, int>> q = nextQ;
	while (!nextQ.empty()) nextQ.pop();
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
				nextQ.push({ nx,ny });
			}
		}
	}
}

void addAir()
{
	// 외부공기 + 내부공기
	// nextQ에는 현재 치즈와 인접한 외부공기이므로,
	// BFS로 탐색하다가 내부공기를 만나면 그 또한 외부공기와 같은 역할이므로 넣어준다.
	// 즉, nextQ에는 기존의 외부공기에 추가적인 내부공기가 외부공기가 되는 부분도 넣어준다.
	queue<pair<int, int>> q = nextQ;
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
				nextQ.push({ nx,ny });
			}
		}
	}
}

bool isFinish()
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

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1)
				b[i][j] = -1;
		}
	}
	divideAir();
	findCheeseAir();
	while (1)
	{
		if (isFinish()) break; // 치즈가 다 녹았는지 체크
		meltCheese();
		finalSize = nextQ.size();
		addAir();
		time++;
	}

	cout << time << '\n' << finalSize << '\n';
	return 0;
}