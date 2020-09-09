#include <iostream>
using namespace std;

// pivot를 가장 앞으로 기준을 두고 정렬한다.
// https://blog.naver.com/ndb796/221226813382 (참조)
void quickSort(int* data, int start, int end) {
	if (start >= end) { // 원소가 1개인 경우
		return;
	}

	int pivot = start;  // pivot
	int i = start + 1;
	int j = end;
	int temp;

	// 엇갈릴 때까지 반복
	while (i <= j) {
		// pivot 값보다 큰 값을 만날 때까지 반복
		while (data[i] <= data[pivot])
			i++;
		// pivot 값보다 작은 값을 만날 때까지 반복
		while (data[j] >= data[pivot] && j > start)
			j--;
		if (i > j) { // 현재 엇갈린 상태면
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	// pivot의 인덱스인 j는 정렬되어있으므로
	// j를 기준으로 왼쪽과 오른쪽을 다시 분할해서 정복하자.
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	int number = 10;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	
	quickSort(arr, 0, number - 1);
	for (int i = 0; i < number; i++)
		cout << arr[i] << ' ';
	return 0;
}