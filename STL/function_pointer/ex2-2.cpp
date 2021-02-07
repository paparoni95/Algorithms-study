#include <iostream>
using namespace std;

/* 함수 포인터 선언과 사용 */

void Print(int n)
{
	cout << "정수: " << n << endl;
}

int main()
{
	void (*pf)(int);
	pf = Print; // 함수의 이름은 함수의 시작 주소

	Print(10); // 1. 함수 호출
	pf(10);    // 2. 포인터를 이용한 함수 호출
	(*pf)(10); // 3. 포인터를 이용한 함수 호출

	cout << endl;
	cout << Print << endl;
	cout << pf << endl;
	cout << *pf << endl;
	return 0;
}