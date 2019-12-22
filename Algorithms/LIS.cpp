#include <iostream>
using namespace std;

/* 
	LIS 알고리즘 (Longest Incresing Subsequence) 최장증가부분수열 

	증가하는 순서대로 숫자를 고르면서 고른 부분 수열의 길이가 최대 길이가 되도록 선택

	동적계획법 중 하나의 테크닉
	O(N^2) 이중루프
	O(NlogN) 세그먼트 트리 구현방식, 이분 탐색 구현방식
*/

// O(N^2) 구현방법
int a[1001];
int d[1001]; // d[i] : i번째 수를 마지막 원소로 가지는 LIS의 길이 (정의)

int main()
{
	int n;
	cin >> n;

	// INPUT
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxLength = 0;
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		// i를 기준으로 (0 ~ i - 1)까지 체크
		for (int j = 0; j < i; j++)
		{
			// 가장 긴 부분을 저장한다.
			if (a[i] > a[j] && d[j] + 1 > d[i])
				d[i] = d[j] + 1;
		}

		if (d[i] > maxLength) 
			maxLength = d[i];
	}

	// OUTPUT
	cout << maxLength;
	return 0;
}