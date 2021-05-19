#include <iostream>
#include <vector>
using namespace std;

int N;
bool a[101][101];

int dy[] = { 0,-1,0,1 };
int dx[] = { 1,0,-1,0 };

int calculateDirection(int d)
{
	if (d + 1 <= 3) return d + 1;
	else return 0;
}

void dragonCurve(int x, int y, int d, int g)
{
	a[y][x] = true;
	vector<int> now_direction, next_direction, temp;
	// 0세대를 먼저 계산해준다.
	int now_x = x + dx[d];
	int now_y = y + dy[d];
	now_direction.push_back(d);
	a[now_y][now_x] = true;

	// 1세대 ~ g세대까지 계산
	for (int i = 1; i <= g; i++)
	{
		next_direction.clear(); temp.clear();
		for (int j = 0; j < now_direction.size(); j++)
		{
			d = now_direction[j];
			if (d + 1 >= 4) d = 0;
			else d = d + 1;

			int next_x = now_x + dx[d];
			int next_y = now_y + dy[d];
			if (next_x >= 0 && next_y >= 0 && next_x <= 100 && next_y <= 100)
			{
				now_x = next_x;
				now_y = next_y;
				a[now_y][now_x] = true;
				next_direction.push_back(d);
			}
		}
		for (int j = next_direction.size() - 1; j >= 0; j--) temp.push_back(next_direction[j]);
		temp.insert(temp.end(), now_direction.begin(), now_direction.end());
		now_direction = temp;
	}
}

int countDragonCurve()
{
	/*
	x1 x2
	x3 x4
	*/
	int cnt = 0;
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			pair<int, int> x1 = { i,j };
			pair<int, int> x2 = { i, j + 1 };
			pair<int, int> x3 = { i + 1, j };
			pair<int, int> x4 = { i + 1,j + 1 };
			if (x2.first < 0 || x2.second < 0 || x2.first > 100 || x2.second > 100) continue;
			if (x3.first < 0 || x3.second < 0 || x3.first > 100 || x3.second > 100) continue;
			if (x4.first < 0 || x4.second < 0 || x4.first > 100 || x4.second > 100) continue;
			if (a[x1.first][x1.second] && a[x2.first][x2.second] && a[x3.first][x3.second] && a[x4.first][x4.second]) cnt++;
		}
	}
	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragonCurve(x, y, d, g);
	}

	int ans = countDragonCurve();
	cout << ans;
	return 0;
}