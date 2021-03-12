#include <iostream>
using namespace std;

/*
	# 투 포인터 알고리즘
	리스트에 순차적으로 접근해야 할 때 2개의 점의 위치를 기록하면서 처리

	ex) 특정한 합을 가지는 부분 연속 수열 찾기 문제

	# 동작 방식
	1. 시작점(start)과 끝점(end)이 첫 번째 원소의 인덱스를 가리키도록 한다.
	2. 현재 부분합이 M과 같다면 카운트한다.
	3. 현재 부분합이 M보다 작으면 end를 1 증가시킨다.
	4. 현재 부분합이 M보다 크거나 같으면 start를 1 증가시킨다.
	5. 모든 경우를 확인할 때까지 2번부터 4번까지의 과정을 반복한다.
*/

int n = 5; // 데이터의 개수
int m = 5; // 찾고자 하는 부분합
int arr[] = { 1,2,3,2,5 }; // 전체 수열

int main()
{
	int cnt = 0;
	int intervalSum = 0;
	int end = 0;

	// start를 차례대로 증가시키며 반복
	for (int start = 0; start < n; start++)
	{
		// end를 가능한 만큼 이동시키기
		while (intervalSum < m && end < n)
		{
			intervalSum += arr[end];
			end++;
		}
		// 부분합이 m일 때 카운트 증가
		if (intervalSum == m) cnt++;
		intervalSum -= arr[start];
	}

	cout << cnt << '\n';
	return 0;
}