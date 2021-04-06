#include <iostream>
#include <string>
using namespace std;

int arr[26];
int main()
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (isalpha(s[i]))
				arr[s[i] - 'a']++;
		}
	}

	int max_cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max_cnt)
			max_cnt = arr[i];
	}

	for (int i = 0; i < 26; i++)
	{
		if (max_cnt == arr[i])
			cout << char('a' + i);
	}

	return 0;
}