#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	priority_queue<int> pq; // max-heap
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
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
			pq.push(x);
	}
	return 0;
}