#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> v;

bool compare(string& a, string& b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto s : v) {
		cout << s << '\n';
	}
	return 0;
}