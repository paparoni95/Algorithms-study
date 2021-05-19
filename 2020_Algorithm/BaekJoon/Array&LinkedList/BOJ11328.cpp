#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	while (n--) {
		string str1, str2;
		cin >> str1 >> str2;

		vector<int> alpha(26, 0);
		for (auto c : str1) {
			alpha[c - 'a']++;
		}
		for (auto c : str2) {
			alpha[c - 'a']--;
		}

		bool ok = true;
		for (auto n : alpha) {
			if (n > 0 || n < 0) {
				ok = false;
				break;
			}
		}

		if (ok) cout << "Possible\n";
		else cout << "Impossible\n";
	}
	return 0;
}