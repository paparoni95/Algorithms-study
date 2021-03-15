#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
priority_queue<int, vector<int>, greater<int> > pq;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pq.push(x);
	}

	while (pq.size() >= 2)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		int sum = a + b;
		ans += sum;
		pq.push(sum);
	}

	cout << ans << '\n';
	return 0;
}