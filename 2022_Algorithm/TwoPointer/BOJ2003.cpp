#include <iostream>
using namespace std;

int N, M;
int arr[10001];

// ������ ������ �ð� �ʰ�.
// �� �����͸� Ȱ���ؼ� ������ �ذ��ؾ� �Ѵ�.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];

	int start = 0;
	int end = 0;
	int sum = arr[0];
	int ans = 0;
	while (end < N)
	{
		// �� �������� �Ǵ� ���θ� �����Ѵ�.
		if (sum < M)
		{
			end++;
			if (end < N)
			{
				sum += arr[end];
			}
		}
		else if (sum > M)
		{
			sum -= arr[start++];
		}
		else
		{
			ans++;
			sum -= arr[start++];
			end++;
			if (end < N)
			{
				sum += arr[end];
			}
		}
	}

	cout << ans << endl;
	return 0;
}