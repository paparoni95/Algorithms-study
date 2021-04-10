#include <iostream>
#include <stack>
using namespace std;

int n, p;
stack<int> st[7];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p;

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;

		while (1)
		{
			if (st[a].empty())
			{
				st[a].push(b);
				cnt++;
				break;
			}
			else if (!st[a].empty() && st[a].top() < b)
			{
				st[a].push(b);
				cnt++;
				break;
			}
			else if (!st[a].empty() && st[a].top() == b)
				break;
			else if (!st[a].empty() && st[a].top() > b)
			{
				st[a].pop();
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}