#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		if (i < n) {
			for (int j = 0; j < n - i - 1; j++) cout << ' ';
			for (int j = 0; j < 2 * (i + 1) - 1; j++) cout << '*';
		}
		else {
			for (int j = 0; j < i - n + 1; j++) cout << ' ';
			for (int j = 0; j < (2 * n - 1) - 2 * (i - n + 1); j++) cout << '*';
		}
		cout << '\n';
	}
	return 0;
}