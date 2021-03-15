#include <iostream>
using namespace std;

/*
	# 선택 정렬 (Selection Sort)
	가장 작은 데이터를 선택해서 정렬되지 않은 데이터 중에서
	가장 앞쪽에 있는 데이터와 위치를 바꾸는 알고리즘

	# 시간 복잡도
	O(N^2)

	N-1번 만큼 가장 작은 수를 찾아서 맨 앞으로 보내야 하며,
	매번 가장 작은 수를 찾기 위해서 비교 연산이 필요하다.
*/

int n = 10;
int arr[10] = { 7,5,9,0,3,1,6,2,4,8 };

int main()
{
	for (int i = 0; i < n; i++)
	{
		int minIdx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[minIdx] > arr[j])
			{
				minIdx = j;
			}
		}
		swap(arr[i], arr[minIdx]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}