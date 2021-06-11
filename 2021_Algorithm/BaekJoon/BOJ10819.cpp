#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, ans;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	do {
		int total = 0;
		for (int i = 0; i < n - 1; i++) {
			total += abs(v[i] - v[i + 1]);
		}
		ans = max(ans, total);
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
	return 0;
}