#include <iostream>
#include <string>
using namespace std;

int tc;
string s;
int main()
{
	cin >> tc;
	while (tc--)
	{
		cin >> s;
		int ret = 0;
		int cnt = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'O')
			{
				ret += cnt;
				cnt++;
			}
			else
			{
				cnt = 1;
			}
		}
		cout << ret << '\n';
	}
	return 0;
}