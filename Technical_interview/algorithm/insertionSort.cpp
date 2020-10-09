#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& v) {
	int key, j;
	// 첫 번째 인덱스는 이미 정렬되어있다고 가정한다.
	for (int i = 1; i < v.size(); i++) {
		key = v[i];

		// 삽입할 곳을 찾는다.
		for (j = i - 1; j >= 0 && v[j] > key; j--) {
			v[j + 1] = v[j]; // 오른쪽으로 이동
		}
		// 삽입할 곳을 찾았다면 그곳에 넣어준다.
		v[j + 1] = key;
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	insertionSort(v);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}