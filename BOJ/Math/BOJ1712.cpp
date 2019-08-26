#include <iostream>
using namespace std;

const int MAX_MONEY = 2100000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	int sales_rate = 0;

	// c * sales_rate > a + ( b * sales_rate)
	// c가 b보다 작거나 같으면 절대 손익분기점이 일어날 수 없다.
	// 반대로 크다면 아래와 같은 공식이 나온다.
	// sales_rate > a / c - b

	if (c <= b) {
		cout << -1;
	}
	else {
		sales_rate = a / (c - b);
		cout << sales_rate + 1;
	}
	return 0;
}