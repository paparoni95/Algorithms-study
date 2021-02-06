#include <iostream>
using namespace std;

/* 함수 호출 연산자 오버로딩() 연산자 */

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "정수 : " << arg << endl;
	}
};

void Print1(int arg)
{
	cout << "정수 : " << arg << endl;
}

int main()
{
	void (*Print2)(int) = Print1;
	FuncObject Print3;

	Print1(10); // '함수'를 사용한 정수 출력
	Print2(10); // '함수 포인터'를 사용한 정수 출력
	Print3(10); // '함수 객체'를 사용한 정수 출력
	
	return 0;
}