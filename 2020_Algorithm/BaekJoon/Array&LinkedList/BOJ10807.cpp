#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i) cin >> v[i];
	int find, answer = 0;
	cin >> find;
	for (int i = 0; i < n; ++i) {
		if (find == v[i])
			++answer;
	}
	cout << answer;
	return 0;
}