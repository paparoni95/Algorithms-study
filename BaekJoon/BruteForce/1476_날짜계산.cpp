#include <iostream>
using namespace std;

int end_e, end_s, end_m;
int e, s, m;
int year;

int main()
{
	cin >> end_e >> end_s >> end_m;
	e = 1, s = 1, m = 1, year = 1;

	if (e == end_e && s == end_s && m == end_m)
	{
		cout << year;
		return 0;
	}

	while (1)
	{
		year++;
		e++; s++; m++;

		if (e >= 16) e = 1;
		if (s >= 29) s = 1;
		if (m >= 20) m = 1;
		if (e == end_e && s == end_s && m == end_m)
			break;
	}

	cout << year;
	return 0;
}