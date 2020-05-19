#include <iostream>
#include <cmath>
using namespace std;

int a[51][51];
int visit[51][51];
int N, L, R;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int mark;
bool mark_check;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[nx][ny] != 0) continue;
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			int diff = abs(a[x][y] - a[nx][ny]);
			if (diff >= L && diff <= R)
			{
				visit[x][y] = mark;
				visit[nx][ny] = mark;
				mark_check = true;
				dfs(nx, ny);
			}
		}
	}
}

void show()
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

void calculate(int door)
{
	int total = 0, cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == door)
			{
				cnt++; // 구역 카운트
				total += a[i][j]; // 총합 
			}
		}
	}

	int average = total / cnt; // 평균값을 구한다.
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == door)
			{
				a[i][j] = average; // 모든 연합을 같은 평균값으로 색칠
			}
		}
	}
}

void initialize()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}
}
void movement_check()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j);
				// 이동이 가능한 인구를 표시했다면, mark를 증가시켜 다음을 준비한다.
				if (mark_check) mark++; 
				mark_check = false;
			}
		}
	}
}

void movement()
{
	// mark가 1부터 색칠해진 곳부터 탐색해서 계산한다.
	int start = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == start)
			{
				calculate(start);
				start++;
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> L >> R;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
		}
	}

	int ans = 0;
	while (1)
	{
		initialize();
		mark = 1;

		movement_check(); 	  // 인구 이동이 가능한지 표시(Mark)한다.
		if (mark == 1) break; // 인구 이동을 하지 않았으면 종료
		                  
		ans++; 
		movement();           // 인구 이동 시작!!
	}
	cout << ans;
	return 0;
}