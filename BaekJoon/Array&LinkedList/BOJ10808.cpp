#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> alpha(26, 0);
	string str;
	cin >> str;
	for (auto ch : str) {
		alpha[ch - 'a']++;
	}
	for (auto e : alpha) {
		cout << e << ' ';
	}
	cout << '\n';
	return 0;
}