#include <iostream>
using namespace std;

// O(Sqrt(N))
bool prime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

int main()
{
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if (prime(num))
			ans++;
	}

	cout << ans;
	return 0;
}