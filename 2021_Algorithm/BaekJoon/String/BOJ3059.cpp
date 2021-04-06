#include <iostream>
#include <string>
using namespace std;

int tc;
string s;
int arr[26];
int main()
{
	cin >> tc;
	while (tc--)
	{
		fill(arr, arr + 26, 0);
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			arr[s[i] - 'A']++;
		}

		int sum = 0;
		for (int i = 0; i < 26; i++)
		{
			if (arr[i] == 0)
				sum += (i + 'A');
		}

		cout << sum << '\n';
	}
	return 0;
}