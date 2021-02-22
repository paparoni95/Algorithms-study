#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int s = 0, e = 1e9;
	int answer = 0;

	while (s <= e)
	{
		long long total = 0;
		int mid = (s + e) / 2;
		for (int i = 0; i < n; i++)
		{
			// 잘랐을 때의 떡의 양 계산
			if (v[i] > mid)
				total += v[i] - mid;
		}

		if (total < m) // 떡의 양이 부족한 경우 더 많이 자르기 (왼쪽 부분 탐색)
			e = mid - 1;
		else
		{
			// 떡의 양이 충분한 경우 덜 자르기 (오른쪽 부분 탐색)
			answer = mid; // 최대한 덜 잘랐을 때가 정답이므로, 여기에서 답을 기록
			s = mid + 1;
		}
	}

	cout << answer << endl;
	return 0;
}