#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[26];
int main()
{
	int n, cnt = 0;
	cin >> n;
	while (n--)
	{
		fill(arr, arr + 26, 0);
		string s;
		cin >> s;
		s.erase(unique(s.begin(), s.end()), s.end());

		bool ok = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (arr[s[i] - 'a'] == 0)
				arr[s[i] - 'a'] = 1;
			else
			{
				ok = false;
				break;
			}
		}

		if (ok) 
			cnt++;
	}

	cout << cnt << '\n';
	return 0;
}