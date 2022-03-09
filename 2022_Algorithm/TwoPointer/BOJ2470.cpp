#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<int> v;

// N의 범위가 10만이기 때문에, 중첩으로 판단은 시간초과를 겪게 된다.
// 투포인터를 활용하자.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end());

	int start = 0;
	int end = N - 1;
	int total = INT_MAX;
	int ans[2] = { 0, 0 };
	while (start < end)
	{
		int sum = v[start] + v[end];

		// 최대한 0에 가까운 수를 찾으려면, 절대값으로 판별하자.
		if (total > abs(sum))
		{
			total = abs(sum);
			ans[0] = v[start];
			ans[1] = v[end];

			if (sum == 0)
				break;
		}

		if (sum < 0)
		{
			start++;
		}
		else
		{
			end--;
		}
	}

	cout << ans[0] << ' ' << ans[1] << endl;
	return 0;
}