#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, answer = 987654321;
int board[21][21];
bool check[21];

int Calculate(const vector<int>& v) {
	int total = 0;
	
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			total += board[v[i]][v[j]];
			total += board[v[j]][v[i]];
		}
	}

	return total;
}

void SelectTeam(int idx, int cnt) {
	if (cnt == n / 2) {
		vector<int> start_team(n / 2);
		vector<int> link_team(n / 2);

		int sidx = 0, lidx = 0;
		for (int i = 0; i < n; ++i) {
			if (check[i] == true)
				start_team[sidx++] = i;
			else
				link_team[lidx++] = i;
		}

		int start_team_point = Calculate(start_team);
		int link_team_point = Calculate(link_team);
		answer = min(answer, abs(start_team_point - link_team_point));
		return;
	}

	for (int i = idx; i < n; ++i) {
		if (check[i] == true) continue;
		check[i] = true;
		SelectTeam(i, cnt + 1);
		check[i] = false;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	SelectTeam(0, 0);
	cout << answer;
	return 0;
}