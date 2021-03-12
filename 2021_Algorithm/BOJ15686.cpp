#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int N, M, ans = 987654321;
int a[51][51];
bool check[51][51];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> picked;

void input()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) house.push_back({ i,j });
			else if (a[i][j] == 2) chicken.push_back({ i,j });
		}
	}
}

void dfs(int cnt, int idx)
{
	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int x1 = house[i].first;
			int y1 = house[i].second;
			int r = 987654321;
			for (int j = 0; j < picked.size(); j++)
			{
				int x2 = picked[j].first;
				int y2 = picked[j].second;
				int diff = abs(x1 - x2) + abs(y1 - y2);
				r = min(r, diff);
			}
			sum += r;
		}

		ans = min(ans, sum);
		return;
	}

	for (int i = idx; i < chicken.size(); i++)
	{
		int x = chicken[i].first;
		int y = chicken[i].second;
		if (check[x][y]) continue;
		check[x][y] = true;
		picked.push_back({ x,y });
		dfs(cnt + 1, i + 1);
		picked.pop_back();
		check[x][y] = false;
	}
}

void solve()
{
	input();
	dfs(0, 0);
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}