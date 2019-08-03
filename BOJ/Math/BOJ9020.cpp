#include <iostream>
#include <climits>
#define SIZE 10001
using namespace std;

bool check[SIZE]; //소수이면 false, 아니면 true

void Eratosthenes() {
	check[0] = true;
	check[1] = true;
	for (int i = 2; i < SIZE; ++i) {
		if (check[i] == false) {
			for (int j = i * i; j < SIZE; j += i) {
				check[j] = true;
			}
		}
	}
}


void GoldBach(int num) {
	int diff = INT_MAX;
	int half = num / 2;
	for (int i = half, j = half; i >= 2; --i, ++j) {
		if (check[i] == false && check[j] == false) {
			if (num == i + j) {
				cout << i << ' ' << j << '\n';
				return;
			}
		}
	}
}


int main() {
	int t;
	cin >> t;
	Eratosthenes();
	for (int testCase = 0; testCase < t; ++testCase) {
		int num;
		cin >> num;
		GoldBach(num);
	}
	return 0;
}