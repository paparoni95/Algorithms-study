#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, result;
vector<int> a, b;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	a.reserve(n);
	b.reserve(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	for (int i = 0; i < n; i++) {
		result += (a[i] * b[i]);
	}
	cout << result << '\n';
	return 0;
}