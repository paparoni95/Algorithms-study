#include <iostream>
#include <string>
using namespace std;

int arr[26];
int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			arr[s[i] - 'A']++;
		else
			arr[s[i] - 'a']++;
	}

	int max_cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max_cnt)
			max_cnt = arr[i];
	}

	int cnt = 0;
	char ch;
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == max_cnt)
		{
			cnt++;
			ch = (char)(i + 'A');
		}
	}

	if (cnt == 1)
		cout << ch << '\n';
	else
		cout << "?\n";
	return 0;
}