// https://yabmoons.tistory.com/47

// 가로선을 어떻게 배분할지가 고민이였는데, 2차원으로 표시하는 방법..
// 다시 풀어보자.
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, H, ans;
int a[11][30];
bool visit[11][30];

bool ladder_game()
{
	for (int i = 1; i <= N; i++) // 세로선
	{
		int cur_num = i;
		for (int j = 1; j <= H; j++) // 가로선 놓을 위치
		{
			// 해당 cur_num(세로선)에서 
			if (visit[cur_num][j] == true) cur_num = cur_num + 1;
			else if (visit[cur_num - 1][j] == true) cur_num = cur_num - 1;
		}

		if (cur_num != i) return false;
	}
	return true;
}

// 가로선 두고나서, 게임 돌려보기
void select_line(int idx, int cnt)
{
	if (cnt >= 4) return;
	if (ladder_game()) // 게임에 성공한다면, 그 때의 가로선의 수를 갱신시킨다.
	{
		cout << cnt << endl;
		for (int i = 1; i <= N; i++) // 세로선
		{
			for (int j = 1; j <= H; j++) // 가로선 놓을 위치
			{
				cout << visit[i][j] << ' ';
			}
			cout << endl;
		}

		cout << endl;
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx; i <= H; i++)
	{
		for (int j = 1; j < N; j++)
		{
			if (visit[j][i] == true) continue;
			if (visit[j - 1][i] == true) continue;
			if (visit[j + 1][i] == true) continue;

			visit[j][i] = true;
			select_line(i, cnt + 1);
			visit[j][i] = false;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	ans = 987654321;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		visit[b][a] = true; // b번 세로선과 b+1 세로선을 a번 가로선으로 이어붙임.
	}

	select_line(1, 0);
	if (ans == 987654321) ans = -1;
	cout << ans;
	return 0;
}