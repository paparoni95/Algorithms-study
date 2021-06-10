#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int len = s.size();
	vector<string> v;
	for (int i = 0; i < len; i++) {
		v.push_back(s.substr(i));
	}

	sort(v.begin(), v.end());
	for (auto ans : v) cout << ans << '\n';
	return 0;
}