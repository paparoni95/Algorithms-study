#include <iostream>
using namespace std;

void swap(int* arr, int p1, int p2) {
	int temp = arr[p1];
	arr[p1] = arr[p2];
	arr[p2] = temp;
}

bool next_permutation(int * arr, int n) {
	int i = n - 1;
	while (i > 0 && arr[i - 1] >= arr[i])
		i -= 1;
	if (i <= 0) return false; //이 순열이 마지막 순열
	int j = n - 1;
	while (arr[j] <= arr[i - 1])
		j -= 1;
	swap(arr, i - 1, j);
	//순서 뒤집기
	j = n - 1;
	while (i < j) {
		swap(arr, i, j);
		++i;
		--j;
	}
	return true; //다음 순열이 있음.
}

int main() {
	int arr[9] = { 1,2,3,4,5,6,7,8 };
	int n;
	scanf("%d", &n);
	do { //첫 순열은 그대로 뱉는다.
		for (int i = 0; i < n; ++i) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	} while (next_permutation(arr, n)); //다음 순열이 있다면 loop를 돌고 아니라면 종료한다.
	return 0;
}