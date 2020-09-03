#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first)
			return true;
		else if (a.first == b.first && a.second < b.second)
			return true;
		else
			return false;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), Compare());
	for (int i = 0; i < n; ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}