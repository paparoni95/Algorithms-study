#include <iostream>
using namespace std;

int n, k, cnt;

int main()
{
	cin >> n >> k;

	while (1)
	{
		// N이 K로 나누어 떨어지는 수가 될 때까지만 1씩 빼기
		int target = (n / k) * k;
		cnt += (n - target);
		n = target;
		// N이 K보다 작을 때 탈출
		if (n < k) break;
		cnt++;
		n /= k;
	}

	// 마지막으로 남은 수에 대하여 1씩 빼기
	cnt += (n - 1);
	cout << cnt << '\n';
	return 0;
}