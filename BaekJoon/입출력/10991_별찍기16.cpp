#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		//blank
		for (int j = 0; j < n - i; j++)
			cout << ' ';
		//star , blank ¼ø
		for (int j = 1; j <= 2 * i - 1; j++)
		{
			if (j % 2 == 1)
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}