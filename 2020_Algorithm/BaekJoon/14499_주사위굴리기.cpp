#include <iostream>
#include <queue>
using namespace std;

int dice[4][3]; // 주사위
int a[21][21];  // 지도
int N, M, K;
pair<int, int> now; // 주사위의 현재위치
pair<int, int> direction[4] = { {0,1}, {0,-1}, {-1,0}, {1,0} }; // 동, 서, 북, 남


int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M >> now.first >> now.second >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}

	queue<int> q;
	for (int i = 0; i < K; i++)
	{
		int command;
		cin >> command;
		q.push(command);
	}

	// 명령어에 따라 다음의 내용을 수행한다.
	while (!q.empty())
	{
		int dir = q.front();
		q.pop();

		int cx = now.first;
		int cy = now.second;

		
		if (dir == 1) // 동쪽
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				// 주사위의 위치를 저장
				now = { nx,ny };

				// 주사위 변경
				int temp = dice[3][1];
				dice[3][1] = dice[1][0];
				dice[1][0] = dice[1][1];
				dice[1][1] = dice[1][2];
				dice[1][2] = temp;

				// 이동한 칸이 0이면 주사위의 바닥면에 쓰인 숫자가 지도에 복사
				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				// 0이 아닌 경우에는 지도에 쓰여진 수가 주사위의 바닥 면에 복사
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}
				
				// 주사위의 가장 윗면을 출력한다.
				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 2) // 서쪽
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[1][2];
				dice[1][2] = dice[1][1];
				dice[1][1] = dice[1][0];
				dice[1][0] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 3) // 북쪽
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[2][1];
				dice[2][1] = dice[1][1];
				dice[1][1] = dice[0][1];
				dice[0][1] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
		else if (dir == 4) // 남쪽
		{
			int nx = cx + direction[dir - 1].first;
			int ny = cy + direction[dir - 1].second;
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				now = { nx,ny };
				int temp = dice[3][1];
				dice[3][1] = dice[0][1];
				dice[0][1] = dice[1][1];
				dice[1][1] = dice[2][1];
				dice[2][1] = temp;

				if (a[nx][ny] == 0) a[nx][ny] = dice[1][1];
				else
				{
					dice[1][1] = a[nx][ny];
					a[nx][ny] = 0;
				}

				cout << dice[3][1] << '\n';
			}
		}
	}


	return 0;
}