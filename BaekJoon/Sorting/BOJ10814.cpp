#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Compare {
	bool operator()(pair<int, string> a, pair<int, string> b) {
		if (a.first < b.first)
			return true;
		else
			return false;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<pair<int, string>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	// 안정 정렬
	// 값이 같은 원소의 전후관계가 바뀌지 않는 정렬
	stable_sort(v.begin(), v.end(), Compare());

	for (int i = 0; i < n; ++i) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	return 0;
}