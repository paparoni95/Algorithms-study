#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_value = -1000000000;
int min_value = 1000000000;

void solve(const vector<int>& a, int sum, int i, int plus, int minus, int mul, int div) {

	// 불가능한 경우
	if (plus < 0 || minus < 0 || mul < 0 || div < 0)
		return;

	// 정답인 경우
	if (i == a.size()) {
		max_value = max(max_value, sum);
		min_value = min(min_value, sum);
		return;
	}

	// 다음 경우
	solve(a, sum + a[i], i + 1, plus - 1, minus, mul, div);
	solve(a, sum - a[i], i + 1, plus, minus - 1, mul, div);
	solve(a, sum * a[i], i + 1, plus, minus, mul - 1, div);
	solve(a, sum / a[i], i + 1, plus, minus, mul, div - 1);
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> operations(4);
	for (int i = 0; i < 4; i++)
		cin >> operations[i];
	solve(v, v[0], 1, operations[0], operations[1], operations[2], operations[3]);
	cout << max_value << '\n' << min_value;
	return 0;
}