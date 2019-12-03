#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int T[16];
int P[16];

void solve(int sum, int day)
{
	// 불가능한 경우
	if (day > n + 1)
		return;

	// 정답인 경우
	if (day == n + 1)
	{
		if (sum > ans)
			ans = sum;

		return;
	}

	// 다음 경우
	solve(sum + P[day], day + T[day]); // day날 상담을 하는 경우
	solve(sum, day + 1);               // day날 상담을 하지 않는 경우
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int t, p;
		cin >> t >> p;
		T[i] = t, P[i] = p;
	}

	solve(0, 1);
	cout << ans;
	return 0;
}