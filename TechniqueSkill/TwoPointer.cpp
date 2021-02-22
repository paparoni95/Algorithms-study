#include <iostream>
#include <vector>
using namespace std;

/*
	투 포인터 알고리즘 : 리스트에 순차적으로 접근해야 할 때
	두 개의 점을 이용하여 위치를 기록하면서 처리하는 기법

	O(N)

	부분 연속 수열의 합을 빠르게 찾고자할 때 사용하는 기법이다.
*/

int n = 5, m = 5; // 데이터의 개수, 부분 연속 수열의 합
vector<int> v = { 1,2,3,2,5 };

int main()
{
	int sum = 0, cnt = 0;
	for (int left = 0, right = 0; left < n; left++)
	{
		// right를 가능한 만큼 이동시키기
		while (sum < m && right < n)
		{
			sum += v[right];
			right++;
		}
		// 부분 합이 m일 때, 카운트 증가
		if (sum == m) cnt++;

		sum -= v[left];
	}

	cout << cnt;
	return 0;
}