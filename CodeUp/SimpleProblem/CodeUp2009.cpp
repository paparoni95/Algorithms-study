#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	
	int ans = 0, cup = 0;
	while (n >= k)
	{
		cup = n / k;
		n = cup + n % k;

		ans += cup;
	}

	cout << ans << endl;
	return 0;
}