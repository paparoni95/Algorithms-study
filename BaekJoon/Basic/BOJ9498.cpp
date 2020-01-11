#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int point;
	cin >> point;

	if (point >= 90 && point <= 100) {
		cout << 'A';
	}
	else if (point >= 80 && point <= 89) {
		cout << 'B';
	}
	else if (point >= 70 && point <= 79) {
		cout << 'C';
	}
	else if (point >= 60 && point <= 69) {
		cout << 'D';
	}
	else {
		cout << 'F';
	}
	return 0;
}