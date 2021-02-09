/* 두 개의 매개변수를 갖는 함수 템플릿도 가능하다. */
#include <iostream>
using namespace std;

template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	Print(10, 1.5);
	Print("Hello!", 100);
	Print(1.5, "Hello!");

	return 0;
}