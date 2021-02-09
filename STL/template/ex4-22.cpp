/* 반환 타입과 매개변수 타입을 인자로 갖는 함수 객체 */
#include <iostream>
#include <string>
using namespace std;

template<typename RetType, typename ArgType>
class Functor
{
public:
	RetType operator()(ArgType data)
	{
		cout << data << endl;
		return RetType();
	}
};

int main()
{
	// void 반환 타입과 int 매개변수 타입을 갖는 함수 객체
	Functor<void, int> functor1;
	functor1(10);

	// bool 반환 타입과 string 매개변수 타입을 갖는 함수 객체
	Functor<bool, string> functor2;
	functor2("Hello!");

	return 0;
}