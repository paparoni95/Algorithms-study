#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 1; j < v.size() - i; j++) {
			if (v[j - 1] > v[j]) {
				swap(v[j - 1], v[j]);
			}
		}
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	bubbleSort(v);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}