#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> card(20);
	for (int i = 0; i < 20; ++i) {
		card[i] = i + 1;
	}

	for (int tc = 0; tc < 10; ++tc) {
		int i, j;
		cin >> i >> j;
		reverse(card.begin() + i - 1, card.begin() + j);
	}

	for (const auto& e : card) {
		cout << e << ' ';
	}
	cout << '\n';
	return 0;
}