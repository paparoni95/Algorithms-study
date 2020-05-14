#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[21][21];
int N, ans = 987654321;

bool check[21];

// 한 팀의 전력을 구한다.
int calculate(vector<int>& v)
{
	int total = 0;
	vector<int> visited(v.size(), 0);
	visited[v.size() - 1] = 1;
	visited[v.size() - 2] = 1;

	do
	{
		vector<int> pos;
		for (int i = 0; i < visited.size(); i++)
		{
			if (visited[i]) pos.push_back(v[i]);
		}

		total += a[pos[0]][pos[1]];
		total += a[pos[1]][pos[0]];

	} while (next_permutation(visited.begin(), visited.end()));

	return total;
}

// 팀 A와 팀 B를 나눈다.
void selectTeam(int idx, int cnt)
{
	if (cnt == N / 2)
	{
		vector<int> teamA, teamB;
		for (int i = 1; i <= N; i++)
		{
			if (check[i] == true) teamA.push_back(i);
			else teamB.push_back(i);
		}

		int teamA_total = calculate(teamA);
		int teamB_total = calculate(teamB);
		//cout << "teamA의 전력은 : " << teamA_total << endl;
		//cout << "teamB의 전력은 : " << teamB_total << endl;
		//cout << "격차는 ? " << abs(teamA_total - teamB_total) << endl;
		ans = min(ans, abs(teamA_total - teamB_total));
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		if (check[i] == true) continue;
		check[i] = true;
		selectTeam(i, cnt + 1);
		check[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> a[i][j];
		}
	}
	
	selectTeam(1, 0);
	cout << ans;
	return 0;
}