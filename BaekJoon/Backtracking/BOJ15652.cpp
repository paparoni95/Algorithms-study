#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void Recursive(int cnt, int idx) {
	if (cnt == m) {
		for (const auto& e : v)
			cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; ++i) {
		v.push_back(i + 1);
		Recursive(cnt + 1, i);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	Recursive(0, 0);
	return 0;
}