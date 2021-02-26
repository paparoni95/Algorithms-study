#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	int m, seed, x1, x2;
	cin >> m >> seed >> x1 >> x2;

	// x1 = (a * seed + c) % m
	// x2 = (a * x1 + c) % m
	for (int a = 0; a < 100; a++)
	{
		for (int c = 0; c < 100; c++)
		{
			if (((a * seed + c) % m == x1) && ((a * x1 + c) % m == x2))
			{
				cout << a << ' ' << c << '\n';
				return 0;
			}
		}
	}

	return 0;
}