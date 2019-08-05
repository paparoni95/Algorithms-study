#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> //intÇü abs()
using namespace std;

int calc(vector<int>& v) {
	int sum = 0;
	for (int i = 1; i < v.size(); ++i) {
		sum += abs(v[i - 1] - v[i]);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int sum = 0;
	do {
		sum = max(sum, calc(v));
	} while (next_permutation(v.begin(), v.end()));

	cout << sum;
	return 0;
}