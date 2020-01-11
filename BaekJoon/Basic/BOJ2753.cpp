#include <iostream>
using namespace std;

int IsLeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int year;
	cin >> year;

	cout << IsLeapYear(year);
	return 0;
}