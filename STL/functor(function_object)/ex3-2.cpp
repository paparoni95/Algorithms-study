#include <iostream>
using namespace std;

void Print(int a, int b)
{
	cout << "전역 함수: " << a << ',' << b << endl;
}

// 매개변수를 갖는 함수 객체
struct Functor
{
	void operator()(int a, int b)
	{
		cout << "함수 객체: " << a << ',' << b << endl;
	}
};

int main()
{
	Functor functor;

	Print(10, 20); // 전역 함수 호출
	functor(10, 20); // 멤버 함수 호출 functor.operator()(10,20)와 같다

	return 0;
}