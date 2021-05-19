#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
void Recursive(int cnt) {
	if (cnt == m) {
		for (const auto e : v)
			cout << e << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		v.push_back(i + 1);
		Recursive(cnt + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;
	Recursive(0);
	return 0;
}