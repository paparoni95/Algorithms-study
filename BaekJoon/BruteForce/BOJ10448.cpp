#include <iostream>
#include <vector>
using namespace std;

int calculator(int n) {
	//Tn = n(n+1)/2
	int sum = n * (n + 1) / 2;
	return sum;
}

bool solve(const vector<int> &a, int sum) {
	for (int i = 0; i < 45; i++) {
		for (int j = 0; j < 45; j++) {
			for (int k = 0; k < 45; k++) {
				if (sum == (a[i] + a[j] + a[k])) 
					return true;
			}
		}
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	vector<int> a(45, 0);
	for (int i = 0; i < 45; i++) { //45까지 삼각수를 구해놓고
		a[i] = calculator(i + 1);
	}

	for (int testCase = 1; testCase <= t; testCase++) {
		int sum;
		cin >> sum;
		if (solve(a, sum)) //문제를 푼다.
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}