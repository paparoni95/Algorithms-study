#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v(7);
	for (int i = 0; i < 7; ++i) cin >> v[i];
	vector<int> odd;
	for (int i = 0; i < 7; ++i) {
		if (v[i] % 2 != 0)
			odd.push_back(v[i]);
	}

	if (odd.empty()) cout << -1;
	else {
		int sum = 0;
		for (int i = 0; i < odd.size(); ++i)
			sum += odd[i];
		cout << sum << '\n' << *min_element(odd.begin(), odd.end());
	}
	return 0;
}