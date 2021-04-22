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
		int m;
		cin >> m;

		priority_queue<int> pq_max;
		priority_queue<int, vector<int>, greater<int>> pq_min;
		vector<int> ret;
		for (int i = 1; i <= m; i++)
		{
			int x;
			cin >> x;

			if (pq_max.size() > pq_min.size())
				pq_min.push(x);
			else
				pq_max.push(x);

			if (!pq_max.empty() && !pq_min.empty())
			{
				if (pq_max.top() > pq_min.top())
				{
					int a = pq_max.top(); pq_max.pop();
					int b = pq_min.top(); pq_min.pop();
					pq_max.push(b);
					pq_min.push(a);
				}
			}

			if (i % 2 == 1)
			{
				ret.push_back(pq_max.top());
			}
		}

		cout << ret.size() << '\n';
		for (int i = 0; i < ret.size(); i++)
		{
			if ((i + 1) % 10 == 0)
				cout << ret[i] << '\n';
			else
				cout << ret[i] << ' ';
		}
		cout << '\n';
	}
	return 0;
}