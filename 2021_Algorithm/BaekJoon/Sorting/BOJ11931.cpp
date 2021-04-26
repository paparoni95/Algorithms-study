#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	set<int, greater<int>> s;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.insert(x);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++)
	{
		cout << *iter << '\n';
	}
	return 0;
}