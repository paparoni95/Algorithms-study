#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	while (n--)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else
			pq.push({ abs(x), x });
	}
	return 0;
}