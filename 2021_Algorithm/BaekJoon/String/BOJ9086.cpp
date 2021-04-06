#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	(cin >> tc).get();
	while (tc--)
	{
		string s;
		cin >> s;

		cout << s.front() << s.back() << '\n';
	}
	return 0;
}