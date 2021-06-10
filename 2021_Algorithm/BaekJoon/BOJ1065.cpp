#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0, diff;
	bool ok;
	for (int i = 1; i <= n; i++) {
		vector<int> v;
		int num = i;
		while (num) {
			v.push_back(num % 10);
			num /= 10;
		}

		ok = true;
		if (v.size() >= 2) {
			diff = v[0] - v[1];

			for (int j = 0; j < v.size() - 1; j++) {
				if (diff == (v[j] - v[j + 1])) continue;
				else {
					ok = false;
					break;
				}
			}
		}
		if (ok) ans++;
	}
	cout << ans << '\n';
	return 0;
}