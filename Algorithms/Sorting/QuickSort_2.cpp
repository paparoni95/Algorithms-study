#include <iostream>
using namespace std;

// pivot를 가장 뒤를 기준을 두고 정렬한다.

void swap(int* data, int a, int b) {
	int temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}

// pivot을 어떤 기준으로 나눌지를 정하는 함수
int partition(int* data, int p, int r) {

	int pivot = data[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++) {
		if (data[j] <= pivot) {
			i++;
			swap(data, i, j);
		}
	}
	swap(data, i + 1, r);
	return i + 1;
}

// p는 첫번째 원소, r은 마지막 원소를 가리킴
void quickSort(int* data, int p, int r) {
	int q;
	if (p < r) {
		q = partition(data, p, r);
		quickSort(data, p, q - 1);
		quickSort(data, q + 1, r);
	}
	else { // 탈출 조건
		return;
	}
}

void printSorted(int* data, int size) {
	cout << "정렬된 배열 : ";
	for (int i = 0; i < size; i++)
		cout << data[i] << ' ';
	cout << endl;
}

int main() {
	int number = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };

	quickSort(arr, 0, number - 1);
	printSorted(arr, number);
	return 0;
}