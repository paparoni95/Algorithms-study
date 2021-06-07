#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, ans;
vector<int> v;
set<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	// a + b + c = d
	// a + b = d - c
	sort(v.begin(), v.end());

	// a + b
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			s.insert(v[i] + v[j]);
		}
	}

	// d - c
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s.find(v[j] - v[i]) != s.end()) {
				ans = max(ans, v[j]);
			}
		}
	}

	cout << ans << '\n';
	return 0;
}