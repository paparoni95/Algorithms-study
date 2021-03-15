#include <iostream>
using namespace std;

/*
	# 계수 정렬 (Counting Sort)
	특정한 값을 가지는 데이터의 개수를 카운트하는 알고리즘
	특정한 조건이 충족될 때, 매우 빠른 정렬 알고리즘


	1. 가장 큰 데이터와 가장 작은 데이터의 범위가 모두 담길 수 있도록 하나의 리스트를 생성
	2. 데이터를 하나씩 확인하며 데이터의 값과 동일한 인덱스의 데이터를 1씩 증가.

	# 시간 복잡도
	데이터의 개수 N, 데이터 중 최대값의 크기를 K라고 할 때
	O(N + K)

	다만, 속도를 향상시키는 대신에 메모리의 양을 잡아먹는다. (TradeOff)
*/

const int MAX_VALUE = 9;
int n = 15;
int arr[15] = { 7,5,9,0,3,1,6,2,9,1,4,8,0,5,2 };
// 모든 범위를 포함하는 배열 선언(모든 값은 0으로 초기화)
int cnt[MAX_VALUE + 1];

int main()
{
	for (int i = 0; i < n; i++)
	{
		cnt[arr[i]]++; // 각 데이터에 해당하는 인덱스의 값 증가
	}
	
	for (int i = 0; i <= MAX_VALUE; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << i << ' ';
		}
	}

	return 0;
}