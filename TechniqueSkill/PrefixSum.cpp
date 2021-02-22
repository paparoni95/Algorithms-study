#include <iostream>
#include <vector>
using namespace std;

/*
	구간 합 알고리즘
	O(N + M) 여기서의 N은 수열의 길이, M은 쿼리를 의미한다.
*/

int n = 5;
vector<int> v = { 10,20,30,40,50 };
vector<pair<int, int>> query = { {1,3},{2,5},{3,4} };

int main()
{
	// 1. 누적합 Prefix Sum 배열을 구한다.
	vector<int> prefixSum(n + 1, 0);
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		prefixSum[i + 1] = v[i] + prefixSum[i];
	}

	// 2. 쿼리당 구간 합 계산
	for (int i = 0; i < query.size(); i++)
	{
		int left = query[i].first;
		int right = query[i].second;

		cout << prefixSum[right] - prefixSum[left - 1] << '\n';
	}

	return 0;
}