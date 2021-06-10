#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> op;
int max_ans = -1e9;
int min_ans = 1e9;

void go(int idx, int total, int plus, int minus, int mul, int div) {
	if (idx >= n) {
		max_ans = max(max_ans, total);
		min_ans = min(min_ans, total);
		return;
	}

	if (plus > 0) go(idx + 1, total + v[idx], plus - 1, minus, mul, div);
	if (minus > 0) go(idx + 1, total - v[idx], plus, minus - 1, mul, div);
	if (mul > 0) go(idx + 1, total * v[idx], plus, minus, mul - 1, div);
	if (div > 0) go(idx + 1, total / v[idx], plus, minus, mul, div - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	op.resize(4);
	for (int i = 0; i < 4; i++) cin >> op[i];

	go(1, v[0], op[0], op[1], op[2], op[3]);
	cout << max_ans << '\n' << min_ans << '\n';
	return 0;
}