#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
bool check[8];

void Recursive(int cnt, int idx) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; ++i) {
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(i + 1);
		Recursive(cnt + 1, i + 1);
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	cin >> n >> m;
	Recursive(0, 0);
	return 0;
}