#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int result = s[0] - '0';
	for (int i = 1; i < s.size(); i++)
	{
		int num = s[i] - '0';
		if (result == 0 || num == 0)
			result += num;
		else if (result == 1 || num == 1)
			result += num;
		else
			result *= num;
	}

	cout << result << '\n';
	return 0;
}
