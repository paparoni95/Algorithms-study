// https://yabmoons.tistory.com/238
// 미세 먼지 확산의 구현이 이상해서 참고했다..
// 2차원 배열의 복사와, 기존 맵과 카피 맵의 유지성에 대해서 아직 미숙한 것 같다.
#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;

int R, C, T;
int room[MAX][MAX];
int copy_room[MAX][MAX];

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };

pair<int, int> machine[2];

void Show()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << room[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "##################################" << endl;
}

void Copy_Room(int A[][MAX], int B[][MAX])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			A[i][j] = B[i][j];
		}
	}
}

void DustMove()
{
	Copy_Room(copy_room, room);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (room[i][j] != 0 && room[i][j] != -1)
			{
				int dust_cnt = 0;
				int dust = room[i][j] / 5;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && ny >= 0 && nx < R && ny < C)
					{
						if (room[nx][ny] != -1)
						{
							copy_room[nx][ny] = copy_room[nx][ny] + dust;
							dust_cnt++;
						}
					}
				}
				copy_room[i][j] = copy_room[i][j] - (dust_cnt * dust);
			}
		}
	}
	Copy_Room(room, copy_room);
}

void AirMove()
{
	int x = machine[0].first;
	int y = machine[0].second;
	int height = x;
	int width = C - 1;

	int Sx, Sy, Ex, Ey;

	Ex = x, Ey = y, Sx = Ex - 1, Sy = Ey;
	for (int i = 0; i < height; i++)
	{
		room[Ex--][Ey] = room[Sx--][Sy];
	}

	Sx = Ex, Sy = Ey + 1;
	for (int i = 0; i < width; i++)
	{
		room[Ex][Ey++] = room[Sx][Sy++];
	}

	Sx = Ex + 1, Sy = Ey;
	for (int i = 0; i < height; i++)
	{
		room[Ex++][Ey] = room[Sx++][Sy];
	}

	Sx = Ex, Sy = Ey - 1;
	for (int i = 0; i < width; i++)
	{
		room[Ex][Ey--] = room[Sx][Sy--];
	}

	room[x][y] = -1;
	room[x][y + 1] = 0;

	x = machine[1].first;
	y = machine[1].second;
	height = R - 1 - x;

	Ex = x, Ey = y, Sx = Ex + 1, Sy = Ey;
	for (int i = 0; i < height; i++)
	{
		room[Ex++][Ey] = room[Sx++][Sy];
	}

	Sx = Ex, Sy = Ey + 1;
	for (int i = 0; i < width; i++)
	{
		room[Ex][Ey++] = room[Sx][Sy++];
	}

	Sx = Ex - 1, Sy = Ey;
	for (int i = 0; i < height; i++)
	{
		room[Ex--][Ey] = room[Sx--][Sy];
	}

	Sx = Ex, Sy = Ey - 1;
	for (int i = 0; i < width; i++)
	{
		room[Ex][Ey--] = room[Sx][Sy--];
	}

	room[x][y] = -1;
	room[x][y + 1] = 0;
}

int CountDust()
{
	int sum = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (room[i][j] > 0) sum += room[i][j];
		}
	}

	return sum;
}

void Simulation()
{
	for (int i = 0; i < T; i++)
	{
		DustMove(); // 미세먼지 확장
		AirMove();  // 공기청정기 바람
	}

	int ans = CountDust(); // 남아있는 미세먼지 카운트
	cout << ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> R >> C >> T;

	int idx = 0;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> room[i][j];
			if (room[i][j] == -1)
			{
				machine[idx].first = i;
				machine[idx].second = j;
				idx++;
			}
		}
	}

	Simulation();
	return 0;
}