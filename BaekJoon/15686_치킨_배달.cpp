// https://yabmoons.tistory.com/50
// next_permutation에 의지하지 말고 재귀를 이용해서 구하는 연습이 필요.
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, chicken_num, ans;
int a[51][51];
bool visited[13];

vector<pair<int, int>> house, chicken, choice;

int calculateDistance()
{
	int total = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int x = house[i].first;
		int y = house[i].second;
		int d = 99999999;

		for (int j = 0; j < choice.size(); j++)
		{
			int xx = choice[j].first;
			int yy = choice[j].second;
			int dist = abs(xx - x) + abs(yy - y);

			d = min(d, dist);
		}

		total += d;
	}
	return total;
}

void selectChicken(int idx, int cnt)
{
	if (cnt == M)
	{
		ans = min(ans, calculateDistance());
		return;
	}

	for (int i = idx; i < chicken_num; i++)
	{
		if (visited[i] == true) continue;
		visited[i] = true;
		choice.push_back(chicken[i]);
		selectChicken(i, cnt + 1);
		visited[i] = false;
		choice.pop_back();
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ans = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 1) house.push_back({ i,j });
			if (a[i][j] == 2) chicken.push_back({ i,j });
		}
	}

	chicken_num = chicken.size();
	selectChicken(0, 0);
	cout << ans;
	return 0;
}