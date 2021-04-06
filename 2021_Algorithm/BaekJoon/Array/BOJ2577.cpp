#include <iostream>
using namespace std;

int cnt[10]; // 0 ~ 9

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int total = a * b * c;

	while (total != 0)
	{
		cnt[total % 10]++;
		total /= 10;
	}

	for (int i = 0; i < 10; ++i)
		cout << cnt[i] << '\n';
	return 0;
}