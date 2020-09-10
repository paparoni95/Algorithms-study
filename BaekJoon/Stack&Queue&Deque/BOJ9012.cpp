#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;

		stack<char> st;
		bool ok = true;
		for (auto c : str) {
			if (st.empty() && c == ')') {
				ok = false;
				break;
			}
			else if (st.empty() && c == '(') {
				st.push('(');
			}
			else if (c == '(') st.push('(');
			else if (c == ')') {
				if (st.top() == '(') st.pop();
				else {
					ok = false;
					break;
				}
			}
		}

		if (!st.empty()) cout << "NO\n";
		else if (ok)     cout << "YES\n";
		else             cout << "NO\n";
	}

	return 0;
}