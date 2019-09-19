#include <iostream>
using namespace std;

// SelectionSort
int main() {
	int i, j, min, index, temp;
	int arr[10] = { 1,10,5,8,7,6,4,3,2,9 };
	for (i = 0; i < 10; i++) {
		min = 9999;
		// 가장 작은 숫자의 인덱스를 찾는다
		for (j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
	}
	for (i = 0; i < 10; i++)
		cout << arr[i] << ' ';
	return 0;
}