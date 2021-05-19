#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	
	string num = to_string(a * b * c);
	vector<int> cnt(10, 0);
	for (auto c : num) {
		cnt[c - '0']++;
	}

	for (auto n : cnt) {
		cout << n << '\n';
	}
	return 0;
}