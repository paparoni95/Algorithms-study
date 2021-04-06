#include <iostream>
#include <string>
using namespace std;

int alpha[26];

int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); ++i)
	{
		alpha[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; ++i)
		cout << alpha[i] << ' ';

	return 0;
}