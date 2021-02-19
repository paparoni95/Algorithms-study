#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

void input()
{
	cin >> n >> c;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
}

bool calc(int mid)
{
	int cnt = 1; // 공유기의 개수
	int cur = v[0];
	for (int i = 1; i < n; i++)
	{
		// 현재의 집에서 다음 집과의 거리가 충분하다면 카운트
		if (v[i] - cur >= mid)
		{
			cnt++;
			cur = v[i];
		}
	}

	// 공유기의 개수를 줄이려면 간격을 넓힌다. (여유가 있다는 의미)
	if (cnt >= c) return true;
	else return false;
}

void solve()
{
	input();
	sort(v.begin(), v.end());

	long long left = 0, right = 1e9;
	int answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		if (calc(mid))
		{
			answer = mid;
			left = mid + 1;
		}
		else // 공유기의 개수를 늘리려면 공유기 사이의 거리를 좁혀야한다.
			right = mid - 1;
	}

	cout << answer << endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("input.txt", "r", stdin);

	solve();

	return 0;
}