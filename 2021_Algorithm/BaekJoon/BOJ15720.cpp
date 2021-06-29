#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// sorting, greedy
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int b, c, d;
	cin >> b >> c >> d;
	vector<int> v1(b);
	vector<int> v2(c);
	vector<int> v3(d);
	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < b; i++) {
		cin >> v1[i];
		ret1 += v1[i];
	}
	for (int i = 0; i < c; i++) {
		cin >> v2[i];
		ret1 += v2[i];
	}
	for (int i = 0; i < d; i++) {
		cin >> v3[i];
		ret1 += v3[i];
	}
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
	sort(v3.begin(), v3.end(), greater<int>());

	int len = min(b, min(c, d));
	for (int i = 0; i < len; i++) {
		int total = v1[i] + v2[i] + v3[i];
		total -= total / 10;
		ret2 += total;
	}

	for (int i = len; i < b; i++) ret2 += v1[i];
	for (int i = len; i < c; i++) ret2 += v2[i];
	for (int i = len; i < d; i++) ret2 += v3[i];
	cout << ret1 << '\n' << ret2;
	return 0;
}
