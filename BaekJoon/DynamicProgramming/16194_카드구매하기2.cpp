#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1001]; // d[i] : 카드 i개를 구매하는 최소비용

int main()
{
	int n;
	cin >> n;

	vector<int> p(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	
	for (int i = 1; i <= n; i++)
		d[i] = 1000 * 10000;

	d[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			if (d[i] > d[i - j] + p[j])
				d[i] = d[i - j] + p[j];

	cout << d[n];
	return 0;
}
