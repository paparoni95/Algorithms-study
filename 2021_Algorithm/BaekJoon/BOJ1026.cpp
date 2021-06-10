#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int sum = 0;
	for (int i = 0; i < n; i++) sum += a[i] * b[i];
	cout << sum << '\n';
	return 0;
}