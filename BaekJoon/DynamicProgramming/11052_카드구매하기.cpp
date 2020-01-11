#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d[1001]; // d[i] : 카드 i개를 구매하는 최대비용

int main()
{
	int n;
	cin >> n;
	vector<int> p(n + 1);   // 카드팩의 가격
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	// D[i] = max(D[i], P[j] + D[i-j]) (1<=j<=i)
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i] = max(d[i], p[j] + d[i - j]);

	cout << d[n];

	return 0;
}