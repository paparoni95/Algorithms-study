/* 함수 템플릿 

   함수 호출 인자 타입을 보고 템플릿 함수의 매개변수 타입을 결정한다.
   즉, 타입이 다른 함수를 얼마든지 만들어내므로 확장성을 가진다.

   컴파일이 완료되면 함수 템플릿은 존재하지 않으며
   인스턴스화된 세 함수가 있다.
   여기서 말하는 세 함수는
   Print<int>(), Print<double>(), Print<const char*>()
*/
#include <iostream>
using namespace std;

template<typename T>
void Print(T a, T b)
{
	cout << a << ", " << b << endl;
}

int main()
{
	// 암시적으로 컴파일러가 타입을 보고 생성함.
	Print(10, 20);
	Print(0.123, 1.123);
	Print("ABC", "abcde");

	// 명시적으로 클라이언트가 직접 지정하여 호출함.
	Print<int>(10, 20);
	Print<double>(0.123, 1.123);
	Print<const char*>("ABC", "abcde");

	return 0;
}