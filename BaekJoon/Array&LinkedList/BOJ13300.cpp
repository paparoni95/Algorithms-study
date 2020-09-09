#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> room[7];
	for (int i = 0; i < n; ++i) {
		int type, group;
		cin >> type >> group;
		room[group].push_back(type);
	}

	int answer = 0;
	for (int i = 0; i < 7; i++) {
		int boy = 0, girl = 0;
		for (int j = 0; j < room[i].size(); ++j) {
			if (room[i][j] == 0) girl++;
			else boy++;
		}

		if (girl % k == 0) {
			answer += girl / k;
		}
		else {
			answer += girl / k + 1;
		}

		if (boy % k == 0) {
			answer += boy / k;
		}
		else {
			answer += boy / k + 1;
		}
	}
	cout << answer;
	return 0;
}