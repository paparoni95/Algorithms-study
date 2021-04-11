#include <iostream>
using namespace std;

int main()
{
	double n = 12.34567;
	cout.precision(2); // 가장 큰 자리수부터 2자리 출력
	cout << n << '\n';

	cout.precision(3); // 12.3
	cout << n << '\n';

	cout.precision(4);
	cout << n << '\n'; // 12.35 (반올림)

	cout << fixed; // 소수점 자릿수 고정
	cout.precision(1);
	cout << n << '\n'; // 12.3

	cout.precision(3);
	cout << n << '\n'; // 12.346 (반올림)

	cout.precision(5);
	cout << n << '\n'; // 12.34567

	return 0;
}