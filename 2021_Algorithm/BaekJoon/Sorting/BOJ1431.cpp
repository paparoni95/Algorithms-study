#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> v;

bool cmp(string& a, string& b)
{
	if (a.size() == b.size())
	{
		int a_sum = 0;
		for (int i = 0; i < a.size(); i++)
		{
			if (isdigit(a[i]))
				a_sum += (a[i] - '0');
		}

		int b_sum = 0;
		for (int i = 0; i < b.size(); i++)
		{
			if (isdigit(b[i]))
				b_sum += (b[i] - '0');
		}

		if (a_sum == b_sum)
			return a < b;
		else
			return a_sum < b_sum;
	}
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.reserve(n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end(), cmp);
	for (auto iter : v)
		cout << iter << '\n';

	return 0;
}