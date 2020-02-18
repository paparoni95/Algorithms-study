#include <iostream>
using namespace std;

int main()
{
	int tc, n1, n2;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		scanf("%d,%d\n", &n1, &n2);
		cout << n1 + n2 << '\n';
	}
	return 0;
}