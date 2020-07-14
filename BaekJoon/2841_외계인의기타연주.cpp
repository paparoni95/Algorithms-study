#include <iostream>
#include <stack>
using namespace std;

int N, P;

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> P;
	stack<int> st[7];
	int ans = 0;

	while (N--)
	{
		int n, p;
		// 음과 피렛
		cin >> n >> p;

		if (st[n].empty())
		{
			ans++;
			st[n].push(p);
			continue;
		}

		if (st[n].top() < p)
		{
			ans++;
			st[n].push(p);
		}
		// 이미 눌려져있으면
		else if (st[n].top() == p)
			continue;
		else
		{
			while (!st[n].empty() && st[n].top() > p)
			{
				ans++;
				st[n].pop();
			}

			// 이미 눌려져있으면
			if (!st[n].empty() && st[n].top() == p) continue;
			ans++;
			st[n].push(p);
		}
	}

	cout << ans;
	return 0;
}