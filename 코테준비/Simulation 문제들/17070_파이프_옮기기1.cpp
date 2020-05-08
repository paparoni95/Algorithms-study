#include <iostream>
#include <queue>
using namespace std;

int n;
int a[17][17];

typedef struct
{
	pair<int, int> left;
	pair<int, int> right;
	int mode; // 0 가로, 1 세로, 2 대각선
}Pipe;

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	queue<Pipe> q;
	Pipe start;
	start.left = { 1,1 };
	start.right = { 1,2 };
	start.mode = 0;
	q.push(start);

	Pipe next;
	int ans = 0;
	while (!q.empty())
	{
		int now_mode = q.front().mode;
		pair<int, int> now_left = q.front().left;
		pair<int, int> now_right = q.front().right;
		q.pop();

		//cout << "현재 파이프의 좌표는 다음과 같습니다. " << endl;
		//cout << "[" << now_left.first << "," << now_left.second << "]" << " " << "[" << now_right.first << "," << now_right.second << "]" << endl;
		//cout << "현재 모드는 : " << now_mode << endl << endl;
		if (now_right.first == n && now_right.second == n)
		{
			ans++;
			continue;
		}

		pair<int, int> next_left;
		pair<int, int> next_right;
		int next_mode;
		if (now_mode == 0)
		{
			// 가로
			next_left = { now_left.first, now_left.second + 1 };
			next_right = { now_right.first, now_right.second + 1 };
			next_mode = 0;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}

		    // 대각선
			next_left = { now_left.first, now_left.second + 1 };
			next_right = { now_right.first + 1, now_right.second + 1 };
			next_mode = 2;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second] && !a[next_right.first-1][next_right.second] && !a[next_right.first][next_right.second-1])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
		}
		else if (now_mode == 1)
		{
			// 세로
			next_left = { now_left.first + 1, now_left.second };
			next_right = { now_right.first + 1, now_right.second };
			next_mode = 1;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
			// 대각선
			next_left = { now_left.first + 1, now_left.second };
			next_right = { now_right.first + 1, now_right.second + 1 };
			next_mode = 2;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second] && !a[next_right.first - 1][next_right.second] && !a[next_right.first][next_right.second - 1])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
		}
		else if (now_mode == 2)
		{
			// 가로
			next_left = { now_left.first + 1, now_left.second + 1 };
			next_right = { now_right.first, now_right.second + 1 };
			next_mode = 0;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
			// 세로
			next_left = { now_left.first + 1, now_left.second + 1 };
			next_right = { now_right.first + 1, now_right.second };
			next_mode = 1;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
			// 대각선
			next_left = { now_left.first + 1, now_left.second + 1 };
			next_right = { now_right.first + 1, now_right.second + 1 };
			next_mode = 2;

			if (next_left.first >= 1 && next_left.second >= 1 && next_left.first <= n && next_left.second <= n)
			{
				if (next_right.first >= 1 && next_right.second >= 1 && next_right.first <= n && next_right.second <= n)
				{
					if (!a[next_right.first][next_right.second] && !a[next_right.first - 1][next_right.second] && !a[next_right.first][next_right.second - 1])
					{
						next.left = next_left;
						next.right = next_right;
						next.mode = next_mode;
						q.push(next);
					}
				}
			}
		}
	}

	cout << ans;
	return 0;
}