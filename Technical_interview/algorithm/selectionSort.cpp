#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& v) {
	for (int i = 0; i < v.size() - 1; i++) {
		int idx = i;
		// 최솟값을 갖는 인덱스 찾기
		for (int j = i + 1; j < v.size(); j++) {
			if (v[idx] > v[j]) {
				idx = j;
			}
		}
		// 최솟값 인덱스가 자기 자신이면 스왑하지 않는다.
		if (i != idx) {
			swap(v[i], v[idx]);
		}
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	selectionSort(v);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}