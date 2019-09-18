#include <iostream>
using namespace std;

int a[10001];
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a[temp]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			cout << i << '\n';
			a[i]--;
		}
	}
	return 0;
}