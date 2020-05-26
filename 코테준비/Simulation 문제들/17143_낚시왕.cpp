// https://yabmoons.tistory.com/288
// 여러차례 시간 초과를 맛보고, 결국 AC 답을 보게 되었다.
// 상어를 움직일 때 모듈러 연산을 이용하면 조금 더 빠르게 움직임을 계산할 수 있다.

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100 + 1
using namespace std;

struct Shark_info
{
	int R;
	int C;
	int Speed;
	int Direct;
	int Size;
	int Num;
};

int R, C, M, answer;
vector<int> stage[MAX][MAX];
vector<Shark_info> Shark;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

bool Standard(int a, int b)
{
	// 오름차순으로 상어의 크기를 정렬하도록 한다.
	if (Shark[a].Size > Shark[b].Size) return true;
	else return false;
}

bool Check()
{
	for (int i = 0; i < Shark.size(); i++)
	{
		if (Shark[i].Size != 0) return false;
	}
	return true;
}

void Fishing(int index)
{
	for (int i = 1; i <= R; i++)
	{
		// 상어가 존재하면
		if (stage[i][index].size() != 0)
		{
			answer += Shark[stage[i][index][0]].Size;
			Shark[stage[i][index][0]].Size = 0; // 상어가 죽었다는 것을 의미
			stage[i][index].clear();            // 맵에 상어를 죽이기.
			break;
		}
	}
}

void MoveShark()
{
	for (int i = 0; i < Shark.size(); i++)
	{
		if (Shark[i].Size == 0) continue;
		int x = Shark[i].R;
		int y = Shark[i].C;
		stage[x][y].clear();
	}

	for (int i = 0; i < Shark.size(); i++)
	{
		if (Shark[i].Size == 0) continue;
		int x = Shark[i].R;
		int y = Shark[i].C;
		int Direct = Shark[i].Direct;
		int Speed = Shark[i].Speed;

		if (Direct == 1 || Direct == 2) // 위, 아래
		{
			int Rotate = (R - 1) * 2;  
			if (Speed >= Rotate) Speed = Speed % Rotate; // Moduler Calculate

			for (int j = 0; j < Speed; j++)
			{
				int nx = x + dx[Direct];
				int ny = y + dy[Direct];
				if (nx < 1) // 상어가 Boundary에 부딪히면 반대방향으로 이동
				{
					Direct = 2;
					nx = nx + 2;
				}

				if (nx > R)
				{
					Direct = 1;
					nx = nx - 2;
				}

				x = nx;
				y = ny;
			}
		}
		else
		{
			int Rotate = (C - 1) * 2;
			if (Speed >= Rotate) Speed = Speed % Rotate;

			for (int j = 0; j < Speed; j++)
			{
				int nx = x + dx[Direct];
				int ny = y + dy[Direct];
				if (ny < 1)
				{
					Direct = 3;
					ny = ny + 2;
				}
				if (ny > C)
				{
					Direct = 4;
					ny = ny - 2;
				}

				x = nx;
				y = ny;
			}
		}

		// 상어가 다 이동했으면 그 좌표로 저장해준다.
		Shark[i].R = x;
		Shark[i].C = y;
		Shark[i].Direct = Direct;
		stage[x][y].push_back(i);
	}
}

void KillShark()
{
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			// 한 칸에 두 마리 이상의 상어가 존재한다면
			if (stage[i][j].size() > 1)
			{
				sort(stage[i][j].begin(), stage[i][j].end(), Standard);

				int live_index = stage[i][j][0];
				for (int k = 1; k < stage[i][j].size(); k++)
				{
					Shark[stage[i][j][k]].Size = 0; // 상어를 죽이고
					Shark[stage[i][j][k]].R = -1;
					Shark[stage[i][j][k]].C = -1;
				}
				stage[i][j].clear();
				stage[i][j].push_back(live_index);
			}
		}
	}
}

void Simulation()
{
	if (M == 0)
	{
		cout << 0 << '\n';
		return;
	}

	for (int i = 1; i <= C; i++)
	{
		if (Check()) break;
		Fishing(i);
		MoveShark();
		KillShark();
	}

	cout << answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark.push_back({ r,c,s,d,z });
		stage[r][c].push_back(i); // 상어의 넘버링
	}

	Simulation();
	return 0;
}