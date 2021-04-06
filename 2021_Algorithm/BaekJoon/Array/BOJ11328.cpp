#include <iostream>
#include <string>
using namespace std;

int tc;
int arr[26];
string str1, str2;

int main()
{
	cin >> tc;
	while (tc--)
	{
		fill(arr, arr + 26, 0);

		cin >> str1 >> str2;
		for (int i = 0; i < str1.length(); ++i)
			arr[str1[i] - 'a']++;
		for (int i = 0; i < str2.length(); ++i)
			arr[str2[i] - 'a']--;

		int cnt = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (arr[i] != 0)
				cnt++;
		}

		if (cnt == 0)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}

	return 0;
}