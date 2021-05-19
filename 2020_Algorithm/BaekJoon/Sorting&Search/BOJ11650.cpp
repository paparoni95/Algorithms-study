#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());
	for (auto p : v) {
		cout << p.first << ' ' << p.second << '\n';
	}
	return 0;
}