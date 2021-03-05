#include <iostream>
using namespace std;

int main()
{
	int h, m;
	cin >> h >> m;

	if (h >= 1)
	{
		if (m - 30 < 0) cout << h - 1 << ' ' << 60 + m - 30;
		else cout << h << ' ' << m - 30;
	}
	else
	{
		if (m - 30 < 0) cout << 23 << ' ' << 60 + m - 30;
		else cout << h << ' ' << m - 30;
	}

	return 0;
}