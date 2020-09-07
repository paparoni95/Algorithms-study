#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) cout << ' ';
		int limit = (2 * n - (2 * (i + 1) - 1));
		for (int j = 0; j < limit; ++j) cout << '*';
		cout << '\n';
	}
	return 0;
}