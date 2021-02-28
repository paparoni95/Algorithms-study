#include <iostream>
using namespace std; // 2751 boj 확인하기

int n = 10;
int arr[1000001];
int tmp[1000001]; // merge sort는 추가적인 배열이 필요함.

void merge(int st, int en)
{
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;
	for (int i = st; i < en; i++)
	{
		if (ridx == en) tmp[i] = arr[lidx++];
		else if (lidx == mid) tmp[i] = arr[ridx++];
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}

	for (int i = st; i < en; i++) arr[i] = tmp[i];
}

void mergeSort(int st, int en)
{
	if (en == st + 1) return;
	int mid = (st + en) / 2;
	mergeSort(st, mid);
	mergeSort(mid + 1, en);
	merge(st, en);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	mergeSort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	return 0;
}