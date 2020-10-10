#include <iostream>
#include <set>
using namespace std;

int n, m, x;
set<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.insert(x);
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (s.find(x) != s.end()) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}