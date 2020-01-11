#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	for (int test_case = 0; test_case < tc; test_case++) {
		int a, b;
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}