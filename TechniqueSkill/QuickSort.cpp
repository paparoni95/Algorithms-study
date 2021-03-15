#include <iostream>
using namespace std;

/*
	# 퀵 정렬 (Quick Sort)
	기준 데이터를 설정하고 그 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 알고리즘
	기준은 여기서 pivot 이라고 한다.

	1. 리스트에서 첫 번째 데이터를 pivot으로 정한다.
	2. 왼쪽에서부터 pivot보다 큰 데이터를 찾고, 오른쪽에서부터 pivot보다 작은 데이터를 찾는다.
	3. 큰 데이터와 작은 데이터의 위치를 swap한다.

	# 시간 복잡도
	best, average : O(NlogN)
	데이터의 개수 N * 높이 logN = NlogN

	Worst : O(N^2), 주어진 리스트가 이미 정렬된 상태라면 매우 느리게 동작한다.
	이는 한쪽으로 편향된 분할을 보여주기 때문이다.
	데이터의 개수 N * 높이 N = N^2
*/

int n = 10;
int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

void quickSort(int arr[], int start, int end)
{
	if (start >= end) return; // 종료조건 원소의 개수가 1개일 때
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right)
	{
		// 왼쪽은 pivot보다 큰 데이터를 찾을 때까지 반복
		while (left <= end && arr[left] <= arr[pivot]) left++;
		// 오른쪽은 pivot보다 작은 데이터를 찾을 때까지 반복
		while (right > start && arr[right] >= arr[pivot]) right--;
		// 엇갈렸다면 작은 데이터와 pivot을 스왑
		if (left > right) swap(arr[pivot], arr[right]);
		// 엇갈리지 않았다면 작은 데이터와 큰 데이터를 스왑
		else swap(arr[left], arr[right]);
	}

	// 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 퀵 정렬을 다시 수행
	quickSort(arr, start, right - 1);
	quickSort(arr, right + 1, end);
}

int main()
{
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	
	return 0;
}