#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int start, int end) {
	// pivot을 가장 왼쪽으로 잡는 경우
	int pivot = v[start];
	int left = start + 1;
	int right = end;
	while (left <= right) {
		while (v[left] <= pivot) left++;
		while (v[right] > pivot) right--;
		// left와 right가 엇갈리지 않았다면 스왑
		if (left <= right) {
			swap(v[left], v[right]);
		}
	}

	// 기존의 pivot 위치와 right 위치를 바꿔준다.
	// pivot을 기준으로 왼쪽은 pivot보다 작은 것들이
	// 오른쪽은 pivot보다 큰 것들이 위치하게 되므로
	// pivot이 가리키는 곳과 right가 가리키는 곳을 바꿔줘야 한다.
	swap(v[start], v[right]);
	return right;
}

void quickSort(vector<int>& v, int start, int end) {
	if (start < end) {
		int pivot = partition(v, start, end);
		quickSort(v, start, pivot - 1);
		quickSort(v, pivot + 1, end);
	}
}

int main() {
	vector<int> v = { 6,9,1,4,3 };
	quickSort(v, 0, v.size() - 1);
	for (auto n : v) {
		cout << n << ' ';
	}
	return 0;
}