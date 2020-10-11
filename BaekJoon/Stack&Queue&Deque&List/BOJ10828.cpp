#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	stack<int> s;
	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int x; cin >> x;
			s.push(x);
		}
		else if (cmd == "pop") {
			if (s.empty()) cout << -1 << '\n';
			else {
				cout << s.top() << '\n';
				s.pop();
			}
		}
		else if (cmd == "size") {
			cout << s.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << s.empty() << '\n';
		}
		else if (cmd == "top") {
			if (s.empty())cout << -1 << '\n';
			else cout << s.top() << '\n';
		}
	}
	return 0;
}