#include <iostream>
using namespace std;

int d[11];
int tc, n;

int main()
{
	cin >> tc;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 10; i++)
	{
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	}

	for (int i = 0; i < tc; i++)
	{
		cin >> n;
		cout << d[n] << '\n';
	}

	return 0;
}