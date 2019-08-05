#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	if (prev_permutation(v.begin(), v.end())) {
		for (int i = 0; i < n; ++i) {
			cout << v[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}