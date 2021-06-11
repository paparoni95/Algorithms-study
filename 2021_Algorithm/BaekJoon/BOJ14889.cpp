#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, half, ans = 987654321;
int maze[20][20];
vector<int> picked;
bool alpha[20];
void dfs(int idx, int cnt) {
	if (cnt == half) {
		vector<int> a;
		vector<int> b;
		a.reserve(half);
		b.reserve(half);
		for (int i = 0; i < n; i++) {
			if (alpha[i]) a.push_back(i);
			else b.push_back(i);
		}

		int a_sum = 0;
		int b_sum = 0;
		for (int i = 0; i < half; i++) {
			for (int j = i + 1; j < half; j++) {
				a_sum += maze[a[i]][a[j]] + maze[a[j]][a[i]];
				b_sum += maze[b[i]][b[j]] + maze[b[j]][b[i]];
			}
		}
		ans = min(ans, abs(a_sum - b_sum));
		return;
	}

	for (int i = idx; i < n; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			dfs(i + 1, cnt + 1);
			alpha[i] = false;
		}
	}
}

int main() {
	cin >> n;
	half = n / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}

	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}
