#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--)
	{
		string s;
		list<char> lt;
		auto cursor = lt.begin();

		cin >> s;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '<')
			{
				if (cursor != lt.begin())
					cursor--;
			}
			else if (s[i] == '>')
			{
				if (cursor != lt.end())
					cursor++;
			}
			else if (s[i] == '-')
			{
				if (cursor != lt.begin())
					cursor = lt.erase(--cursor);
			}
			else
			{
				lt.insert(cursor, s[i]);
			}
		}

		for (auto c : lt)
			cout << c;
		cout << '\n';
	}
	return 0;
}