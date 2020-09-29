#include <bits/stdc++.h>
using namespace std;

int n;
long long answer1 = -1e9, answer2 = 1e9;
vector<int> v;
vector<int> op;

void solution(int index, long long sum, int plus, int minus, int mul, int div) {
	if (index >= v.size()) {
		answer1 = max(answer1, sum);
		answer2 = min(answer2, sum);
		return;
	}
	if (plus > 0) {
		solution(index + 1, sum + v[index], plus - 1, minus, mul, div);
	}
	if (minus > 0) {
		solution(index + 1, sum - v[index], plus, minus - 1, mul, div);
	}
	if (mul > 0) {
		solution(index + 1, sum * v[index], plus, minus, mul - 1, div);
	}
	if (div > 0) {
		solution(index + 1, sum / v[index], plus, minus, mul, div - 1);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	for (int i = 0; i < 4; i++) {
		int x;
		cin >> x;
		op.push_back(x);
	}

	solution(1, v[0], op[0], op[1], op[2], op[3]);
	cout << answer1 << '\n' << answer2 << '\n';
	return 0;
}