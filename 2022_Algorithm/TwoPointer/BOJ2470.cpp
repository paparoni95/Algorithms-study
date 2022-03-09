#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<int> v;

// N�� ������ 10���̱� ������, ��ø���� �Ǵ��� �ð��ʰ��� �ް� �ȴ�.
// �������͸� Ȱ������.
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

		// �ִ��� 0�� ����� ���� ã������, ���밪���� �Ǻ�����.
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