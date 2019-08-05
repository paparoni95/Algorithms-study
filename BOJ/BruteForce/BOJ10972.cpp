#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	if (next_permutation(v.begin(), v.end())) { //다음 순열이 있다면 출력
		for (int i = 0; i < n; ++i) {
			cout << v[i] << ' ';
		}
	}
	else { //다음 순열이 없다면 -1을 출력
		cout << -1;
	}
	return 0;
}