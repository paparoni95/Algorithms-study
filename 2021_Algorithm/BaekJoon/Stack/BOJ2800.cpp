#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string s;
vector<string> ret;
vector<pair<int, int>> v;
set<string> vis;
bool picked[10];
bool erase[210];

// °ýÈ£½ÖÀ» Á¦°ÅÇØ¼­ ¹®ÀÚ¿­À» ¸¸µç´Ù.
void dfs(int idx, int cnt)
{
	if (cnt >= 1)
	{
		string make;
		for (int i = 0; i < s.length(); i++)
		{
			if (!erase[i])
				make += s[i];
		}

		if (vis.find(make) == vis.end())
		{
			vis.insert(make);
			ret.push_back(make);
		}
	}

	for (int i = idx; i < v.size(); i++)
	{
		if (!picked[i])
		{
			picked[i] = true;
			erase[v[i].first] = true;
			erase[v[i].second] = true;
			dfs(i, cnt + 1);
			erase[v[i].second] = false;
			erase[v[i].first] = false;
			picked[i] = false;
		}
	}
}

int main()
{
	cin >> s;
	stack<int> st;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			st.push(i);
		else if (s[i] == ')')
		{
			int j = st.top();
			st.pop();
			v.push_back({ j,i }); // °ýÈ£½Ö ÀúÀå
		}
	}

	dfs(0, 0);

	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); i++)
		cout << ret[i] << '\n';
	return 0;
}