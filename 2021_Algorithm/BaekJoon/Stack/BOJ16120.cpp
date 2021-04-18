#include <iostream>
#include <string>
using namespace std;

string s1, s2 = "PPAP";
char ret[1000001];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s1;
	int idx = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		ret[idx++] = s1[i];

		if (ret[idx - 1] == s2[s2.length() - 1])
		{
			if (idx - s2.length() < 0)
				continue;

			bool ok = true;
			for (int j = 0; j < s2.length(); j++)
			{
				if (ret[idx - j - 1] != s2[s2.length() - j - 1])
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				idx -= s2.length();
				ret[idx++] = 'P';
			}
		}
	}

	if (idx != 1)
		cout << "NP\n";
	else
	{
		if (ret[idx - 1] == 'P')
			cout << "PPAP\n";
		else
			cout << "NP\n";
	}
	return 0;
}