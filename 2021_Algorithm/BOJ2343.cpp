#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void input()
{
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
}

bool calc(long long mid)
{
	int cnt = 1; // 블루레이의 개수
	int sum = 0; // 현재까지 영상 길이의 합
	for (int i = 0; i < n; i++)
	{
		// 하나의 영상이 블루레이 크기보다 크면 불가능
		if (v[i] > mid)  return false;
		sum += v[i];
		
		// 하나를 더 담았는데 블루레이가 터진 경우 -> 추가
		if (sum > mid)
		{
			sum = v[i];
			cnt++;
		}
	}

	// 조건을 만족한다면(블루레이 개수를 가급적 줄이려고 한다)
	if (cnt <= m) return true;
	else return false;
}

void solve()
{
	input();

	long long left = 0, right = 1e9;
	long long answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		// 블루레이 크기를 최소로 하면서 동시에 블루레이의 개수를 줄이는 조건에 만족한다면
		if (calc(mid))
		{
			answer = mid;
			right = mid - 1;
		}
		else // 그룹을 줄여야하기 때문에 블루레이 크기를 더 크게 설정한다.
			left = mid + 1;
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