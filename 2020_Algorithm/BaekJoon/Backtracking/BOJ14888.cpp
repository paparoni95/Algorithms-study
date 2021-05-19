#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000000;
int n;
pair<long long, long long> answer = { MAX, -MAX };
vector<int> v;
vector<int> op(4);

void Recursive(int idx, int plus, int minus, int mul, int div, long long sum) {
	if (idx >= v.size()) {
		answer.first = min(answer.first, sum);
		answer.second = max(answer.second, sum);
		return;
	}
		
	if (plus > 0)
		Recursive(idx + 1, plus - 1, minus, mul, div, sum + v[idx]);
	if (minus > 0)
		Recursive(idx + 1, plus, minus - 1, mul, div, sum - v[idx]);
	if (mul > 0)
		Recursive(idx + 1, plus, minus, mul - 1, div, sum * v[idx]);
	if (div > 0)
		Recursive(idx + 1, plus, minus, mul, div - 1, sum / v[idx]);
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	for (int i = 0; i < 4; ++i) {
		cin >> op[i];
	}

	Recursive(1, op[0], op[1], op[2], op[3], v[0]);
	cout << answer.second << '\n' << answer.first;
	return 0;
}