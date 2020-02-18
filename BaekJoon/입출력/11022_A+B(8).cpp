#include <iostream>
using namespace std;

int main()
{
	int tc, n1, n2;
	cin >> tc;
	for (int i = 1; i <= tc; i++)
	{
		cin >> n1 >> n2;
		cout << "Case #" << i << ": " << n1 << " + " << n2 << " = " << n1 + n2 << "\n";
	}
	return 0;
}