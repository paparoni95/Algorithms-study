#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int result;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int minValue = 10001;
		for (int j = 0; j < m; j++)
		{
			int x;
			cin >> x;
			minValue = min(minValue, x);
		}
		result = max(result, minValue);
	}

	cout << result << '\n';
	return 0;
}