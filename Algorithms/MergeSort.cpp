#include <iostream>
using namespace std;

int number = 8;
int sorted[8]; // 추가적인 메모리 공간이 필요

// 합치는 순간에 정렬을 수행한다.
void merge(int* arr, int first, int mid, int end) {
	int i = first;
	int j = mid + 1;
	int k = first;
	// 작은 순서대로 배열에 삽입
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}
	// 남은 데이터도 순서대로 삽입
	if (i > mid) { // right 배열의 데이터가 남아있는 경우
		for (int t = j; t <= end; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	else { // left 배열의 데이터가 남아있는 경우
		for (int t = i; t <= mid; t++) {
			sorted[k] = arr[t];
			k++;
		}
	}
	// 정렬된 배열을 원래 배열에 복사한다.
	for (int t = first; t <= end; t++) {
		arr[t] = sorted[t];
	}
}

void mergeSort(int* arr, int first, int end) {
	// 크기가 1보다 큰 경우
	if (first < end) {
		int mid = (first + end) / 2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, first, mid, end);
	}
}

int main() {
	int array[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(array, 0, number - 1);
	for (int i = 0; i < number; i++) {
		cout << array[i] << ' ';
	}
	return 0;
}