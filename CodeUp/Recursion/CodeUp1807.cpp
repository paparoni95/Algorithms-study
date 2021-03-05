#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b;

int go(int n)
{
	int cnt = 1;
	
	if (n == 1) return 1;
	if (n % 2 != 0) cnt += go(n * 3 + 1);
	else cnt += go(n / 2);

	return cnt;
}

int main()
{
	cin >> a >> b;

	int n, len = 0;
	for (int i = a; i <= b; i++)
	{
		int ret = go(i);
		if (len < ret)
		{
			len = ret;
			n = i;
		}
	}

	cout << n << ' ' << len << endl;
	return 0;
}