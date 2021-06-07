#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v[5001];
int dp[5001];
int height[5001];

int go(int cur) {
	if (dp[cur] != 0) return dp[cur];
	for (int i = 0; i < v[cur].size(); i++) {
		dp[cur] = max(dp[cur], go(v[cur][i]));
	}
	return ++dp[cur]; //자기 자신 추가
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> height[i];
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (height[a] < height[b]) v[a].push_back(b);
		else v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		cout << go(i) << '\n';
	}
	return 0;
}