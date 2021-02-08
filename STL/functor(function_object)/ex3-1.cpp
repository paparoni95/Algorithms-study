#include <iostream>
using namespace std;

// 함수 객체 정의 (다른 말로 Functor라고도 부름)

void Print()
{
	cout << "전역 함수!" << endl;
}

struct Functor
{
	void operator()()
	{
		cout << "함수 객체!" << endl;
	}
};

int main()
{
	Functor functor;

	Print(); // 전역 함수 호출
	functor(); // 멤버 함수 호출 functor.operator()와 같다

	return 0;
}