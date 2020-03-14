#include <iostream>
#include <string>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int loop;
		cin >> loop;

		// C스타일은 char str[] 형태로 입력받는다.
		string str;
		cin >> str;

		// str.size()는 O(1)
		// C스타일의 strlen()은 O(N)
		for (int i = 0; i < str.size(); i++)
		{
			for (int j = 0; j < loop; j++)
				cout << str[i];
		}
		cout << '\n';
	}
	return 0;
}