#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int cnt = 1;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
			++cnt;
	}

	if (str.front() == ' ') --cnt;
	if (str.back() == ' ') --cnt;

	cout << cnt << '\n';
	return 0;
}