#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

bool Compare(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;

	// N개의 정수를 입력받아 리스트에 저장
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), Compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << ' ';
	}
	return 0;
}