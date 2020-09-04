#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
bool check[8];
int n, m;

void Recursive(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < v.size(); ++i)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (check[i] == true) continue;
		check[i] = true;
		v.push_back(i + 1);
		Recursive(cnt + 1);
		v.pop_back();
		check[i] = false;
	}
}


int main() {
	cin >> n >> m;
	Recursive(0);
	return 0;
}