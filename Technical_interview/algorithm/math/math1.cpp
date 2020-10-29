#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	double dNum = 1234.56789;
	printf("dNum : %lf\n", dNum);
	// 소수점 아래의 자릿수 = %f 점의 오른쪽에 있는 값
	// 그 자릿수를 맞추기 위해 자동으로 값을 반홀림하여 출력함
	// C style
	printf("%.0f\n", dNum);
	printf("%.1f\n", dNum);
	printf("%.2f\n", dNum);
	printf("%.3f\n", dNum);
	printf("%.4f\n\n", dNum);

	printf("dNum : %lf\n", dNum);
	// C++ style
	cout << "dNum : " << dNum << '\n'; // 아무런 설정 없이 출력했을 때, 전체 자릿수가 6으로 고정, 마찬가지로 자동으로 반올림

	cout.precision(5);    // 자릿수를 조정하는 함수, 전체 자릿수를 5로 조절한 것
	cout << "dNum : " << dNum << '\n';

	cout << fixed;        // 소숫점 아래 값을 고정하는 표현이다.
	cout.precision(6);    // fixed 이후에 precision을 입력하면 소숫점 아래를 6으로 고정한다는 뜻
	cout << "dNum : " << dNum << '\n';

	cout.unsetf(ios::fixed); // .setf와 반대되는 표현이 .unsetf이며, 이는 설정 해제를 의미한다.
	cout << "dNum : " << dNum << '\n';

	cout.setf(ios::fixed); // .fixed라는 표현은 .setf(ios::fixed)로 사용할 수 있다.
	cout.precision(5);     // 이후에 소수점 아래 자릿수를 5로 고정했다.
	cout << "dNum : " << dNum << '\n';
	return 0;
}
