#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	(cin >> n).get();
	string s;
	while (n--)
	{
		getline(cin, s);

		s[0] = toupper(s[0]);
		cout << s << '\n';
	}
	return 0;
}