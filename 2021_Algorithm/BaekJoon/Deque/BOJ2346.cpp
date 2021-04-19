#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n;
deque<pair<int,int>> dq;
vector<int> ret;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		dq.push_back({ x, i + 1 });
	}

	bool left = true;
	int bomb = dq.front().first;
	int idx = dq.front().second;
	ret.push_back(idx);
	dq.pop_front();
	while (!dq.empty())
	{
		if (bomb > 0)
		{
			for (int i = 0; i < bomb - 1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}

			bomb = dq.front().first;
			idx = dq.front().second;
			dq.pop_front();
		}
		else
		{
			bomb *= -1;
			for (int i = 0; i < bomb - 1; i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}

			bomb = dq.back().first;
			idx = dq.back().second;
			dq.pop_back();
		}

		ret.push_back(idx);
	}
	
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << ' ';
	cout << '\n';

	return 0;
}