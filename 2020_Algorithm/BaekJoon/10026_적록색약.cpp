#include <iostream>

#define MAX_SIZE 100 + 1
using namespace std;

int N;
char a[MAX_SIZE][MAX_SIZE];
char b[MAX_SIZE][MAX_SIZE]; // Copy 맵

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

void dfsTypeOne(int x, int y, char type)
{
	a[x][y] = '#';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (a[nx][ny] == type) dfsTypeOne(nx, ny, type);
		}
	}
}

void dfsTypeTwo(int x, int y, char type)
{
	b[x][y] = '#';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N)
		{
			if (b[nx][ny] == type) dfsTypeTwo(nx, ny, type);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			
			if (a[i][j] == 'G')
				b[i][j] = 'R';
			else
				b[i][j] = a[i][j];
		}
	}

	// 정상인 시야
	int person_a = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] != '#')
			{
				person_a++;
				dfsTypeOne(i, j, a[i][j]);
			}
		}
	}
	// 적록색약 시야
	int person_b = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (b[i][j] != '#')
			{
				person_b++;
				dfsTypeTwo(i, j, b[i][j]);
			}
		}
	}
	
	cout << person_a << ' ' << person_b;
	return 0;
}