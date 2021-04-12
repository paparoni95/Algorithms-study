#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

stack<pair<int, int>> st;
vector<pair<int, int >> v;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end());

	int w = 0, h = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second > h)
		{
			w = v[i].first;
			h = v[i].second;
		}
	}

	int ret = 0;
	// left
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first == w && v[i].second == h)
		{
			if(!st.empty())
				ret += abs(v[i].first - st.top().first) * st.top().second;
			break;
		}
	    else
		{
			if (st.empty())
				st.push(v[i]);
			else if (!st.empty() && st.top().second < v[i].second)
			{
				ret += abs(v[i].first - st.top().first) * st.top().second;
				st.pop();
				st.push(v[i]);
			}
		}
	}
	// right
	while (!st.empty()) st.pop();
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i].first == w && v[i].second == h)
		{
			if(!st.empty())
				ret += abs(v[i].first - st.top().first) * st.top().second;
			break;
		}
		else
		{
			if (st.empty())
				st.push(v[i]);
			else if (!st.empty() && st.top().second < v[i].second)
			{
				ret += abs(v[i].first - st.top().first) * st.top().second;
				st.pop();
				st.push(v[i]);
			}
		}
	}
	ret += h;
	cout << ret << '\n';
	return 0;
}