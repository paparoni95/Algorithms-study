#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	vector<int> buger(3);
	vector<int> drink(2);

	for (int i = 0; i < 3; i++) cin >> buger[i];
	for (int i = 0; i < 2; i++) cin >> drink[i];

	int ans = 4000, sum = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			sum = buger[i] + drink[j] - 50;
			ans = min(ans, sum);
		}
	}

	cout << ans;
	return 0;
}