#include <iostream>
#include <string>
using namespace std;

string str;
int a, b, c, d;

int main()
{
	while (getline(cin, str))
	{
		a = b = c = d = 0;

		for (int i = 0; i < str.length(); ++i)
		{
			if (islower(str[i])) a++;
			else if (isupper(str[i])) b++;
			else if (isdigit(str[i])) c++;
			else d++;
		}

		cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
	}
	return 0;
}