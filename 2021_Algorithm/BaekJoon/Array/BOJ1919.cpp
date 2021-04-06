#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int arr[26];

int main()
{
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); ++i)
		arr[str1[i] - 'a']++;
	for(int i = 0; i < str2.length(); ++i)
		arr[str2[i] - 'a']--;

	int cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (arr[i] != 0)
			cnt += abs(arr[i]);
	}

	cout << cnt << '\n';
	return 0;
}