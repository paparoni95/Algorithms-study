#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int left, int right, int mid) {
	vector<int> tmp; // 추가적인 배열이 필요하다.
	int i = left;
	int j = mid + 1;
	int cnt = 0;
	// 분할 정렬된 list를 합병한다.
	while (i <= mid && j <= right) {
		if (v[i] <= v[j]) {
			tmp.push_back(v[i++]);
		}
		else {
			tmp.push_back(v[j++]);
		}
	}

	// 남아있는 값들을 뒤에 채운다.
	while (i <= mid) {
		tmp.push_back(v[i++]);
	}
	while (j <= right) {
		tmp.push_back(v[j++]);
	}

	// 원래 배열에 복사한다.
	for (int k = left; k <= right; k++) {
		v[k] = tmp[cnt++];
	}
}

void mergeSort(vector<int>& v, int start, int end) {
	// 만약 크기가 1조각이라면 left == right이므로 탈출
	// 이는 정렬되었다는 것을 의미한다.
	// 아니라면 계속해서 반으로 쪼개 정복한다.
	if (start < end) {
		int mid = (start + end) / 2; // 균등(divide)
		mergeSort(v, start, mid);    // 앞쪽 부분 배열 정렬(conquer)
		mergeSort(v, mid + 1, end);  // 뒤쪽 부분 배열 정렬(conquer)
		merge(v, start, end, mid);   // 정렬된 2개의 부분 배열을 병합하는 과정(combine)
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	mergeSort(v, 0, v.size() - 1);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}