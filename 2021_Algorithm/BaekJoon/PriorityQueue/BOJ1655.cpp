#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int> pq_max;
	priority_queue<int, vector<int>, greater<int>> pq_min;
	while (n--)
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
				// swap
				int a = pq_max.top(); pq_max.pop();
				int b = pq_min.top(); pq_min.pop();
				pq_min.push(a);
				pq_max.push(b);
			}
		}
		cout << pq_max.top() << '\n';
	}
	return 0;
}