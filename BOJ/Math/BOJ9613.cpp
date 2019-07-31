#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int main() {
	int t;
	cin >> t;
	for (int testCase = 0; testCase < t; testCase++) {
		int n;
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		long long sum = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(v[i], v[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
