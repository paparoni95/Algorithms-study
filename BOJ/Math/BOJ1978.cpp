#include <iostream>
using namespace std;

int a[101];
int n, ans;


//해당 숫자가 소수인지 판별
bool IsPrime(int num) {
	if (num < 2) {
		return false;
	}

	for (int i = 2; i * i <= num; ++i) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		if (IsPrime(a[i])) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}