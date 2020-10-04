#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
	cin >> n;

	v.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int start = 0, end = v.size() - 1;
	int mid = (start + end) / 2;
	cout << v[mid] << '\n';
	return 0;
}