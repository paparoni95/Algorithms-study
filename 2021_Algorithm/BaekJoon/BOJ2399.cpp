#include <iostream>
#include <cmath>
using namespace std;

long long arr[10001];
int main() {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += abs(arr[i] - arr[j]);
		}
	}
	cout << ans << '\n';
	return 0;
}