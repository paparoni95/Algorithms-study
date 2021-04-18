#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		queue<pair<int, int>> q; // (priority, num)
		priority_queue<int> pq;  // priority
		int n, m;

		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			q.push({ x, i }); 
			pq.push(x);
		}

		int cnt = 0;
		while (!q.empty())
		{
			int now = q.front().first;
			int num = q.front().second;

			if (!pq.empty() && now < pq.top())
			{
				q.push(q.front());
				q.pop();
				continue;
			}

			cnt++;
			pq.pop();
			q.pop();
			if (m == num)
			{
				cout << cnt << '\n';
				break;
			}
		}
	}
	return 0;
}