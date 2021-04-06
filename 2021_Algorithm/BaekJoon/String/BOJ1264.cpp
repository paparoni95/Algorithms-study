#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.length() == 1 && s.front() == '#')
			break;

		int cnt = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
				|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
				cnt++;
		}

		cout << cnt << '\n';
	}
	return 0;
}