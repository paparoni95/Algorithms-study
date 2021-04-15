#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	queue<int> q;
	for (int i = 1; i <= n; i++)
		q.push(i);

	vector<int> ret;
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		ret.push_back(q.front());
		q.pop();
	}

	cout << '<';
	for (int i = 0; i < n - 1; i++)
		cout << ret[i] << ", ";
	cout << ret[n - 1] << ">\n";
	return 0;
}