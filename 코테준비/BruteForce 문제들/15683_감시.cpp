// https://yabmoons.tistory.com/46
// 문제는 금방 이해됬으나, CCTV의 모든 경우를 고려하는 부분의 구현이 까다로웠다.
// 나중에 다시 풀어보자.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;
int a[9][9];   // 맵
int c_a[9][9]; // 복사 맵

vector<pair<pair<int,int>, pair<int,int>>> v; // CCTV [(x,y),(번호,방향)]

void copy_Map()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			c_a[i][j] = a[i][j];
		}
	}
}

void right(int x, int y)
{
	for (int i = y + 1; i < M; i++)
	{
		if (c_a[x][i] == 6) break;
		if (c_a[x][i] >= 1 && c_a[x][i] <= 5) continue;

		c_a[x][i] = -1;
	}
}

void left(int x, int y)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (c_a[x][i] == 6) break;
		if (c_a[x][i] >= 1 && c_a[x][i] <= 5) continue;

		c_a[x][i] = -1;
	}
}

void down(int x, int y)
{
	for (int i = x + 1; i < N; i++)
	{
		if (c_a[i][y] == 6) break;
		if (c_a[i][y] >= 1 && c_a[i][y] <= 5) continue;

		c_a[i][y] = -1;
	}
}

void up(int x, int y)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (c_a[i][y] == 6) break;
		if (c_a[i][y] >= 1 && c_a[i][y] <= 5) continue;

		c_a[i][y] = -1;
	}
}

void check_cctv_area()
{
	copy_Map();
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second.first == 1)
		{
			if (v[i].second.second == 0) right(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 1) left(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 2) down(v[i].first.first, v[i].first.second);
			else if (v[i].second.second == 3) up(v[i].first.first, v[i].first.second);
		}
		else if (v[i].second.first == 2)
		{
			if (v[i].second.second == 0 || v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2 || v[i].second.second == 3)
			{
				up(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3)
		{
			if (v[i].second.second == 0)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4)
		{
			if (v[i].second.second == 0)
			{
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1)
			{
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2)
			{
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3)
			{
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 5)
		{
			right(v[i].first.first, v[i].first.second);
			down(v[i].first.first, v[i].first.second);
			left(v[i].first.first, v[i].first.second);
			up(v[i].first.first, v[i].first.second);
		}
	}
}

int numOfSecretArea()
{
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (c_a[i][j] == 0) total++;
		}
	}
	return total;
}

// CCTV 방향을 미리 정해놓고, 그 상태에서 사각지대를 구해서 저장한다. (재귀)
void set_CCTV_Direction(int cnt)
{
	if (cnt == v.size())
	{
		// 정해진 방향대로 CCTV를 검사하고,
		check_cctv_area();
		// 사각지대를 구해서 최소 크기를 구한다.
		ans = min(ans, numOfSecretArea());
		return;
	}

	v[cnt].second.second = 0;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 1;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 2;
	set_CCTV_Direction(cnt + 1);

	v[cnt].second.second = 3;
	set_CCTV_Direction(cnt + 1);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ans = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
			if (a[i][j] >= 1 && a[i][j] <= 5)
				v.push_back({ {i,j},{a[i][j], -1} });
		}
	}

	set_CCTV_Direction(0);
	cout << ans;
	return 0;
}