#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n, find_page;
		cin >> n >> find_page;
		queue<int> q;      // 문서의 정보
		vector<int> order; // 우선순위
		for (int i = 0; i < n; i++)
		{
			int priority;
			cin >> priority;
			q.push(i);
			order.push_back(priority);
		}

		int cnt = 0;
		while (!q.empty())
		{
			int now_priority = order.front();
			int now_page = q.front();
			q.pop();

			if (order.size() >= 2) order.erase(order.begin(), order.begin() + 1);

			int max_priority = *max_element(order.begin(), order.end());
			// 인쇄
			if (now_priority >= max_priority)
			{
				cnt++;
				if (find_page == now_page)
				{
					break;
				}
			}
			else
			{
				q.push(now_page);
				order.push_back(now_priority);
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}