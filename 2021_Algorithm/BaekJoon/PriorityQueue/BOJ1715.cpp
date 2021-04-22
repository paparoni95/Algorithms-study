#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}
	
	int ret = 0;
	while (pq.size() > 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();

		ret += (a + b);
		pq.push(a + b);
	}

	cout << ret << '\n';
	return 0;
}