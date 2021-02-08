#include <iostream>
using namespace std;

/* 함수 객체의 장점
   
   함수처럼 동작하는 객체
   다른 멤버 변수와 멤버 함수를 가질 수 있다.
   함수 객체의 서명이 같더라도 객체 타입이 다르면 서로 전혀 다른 타입으로 인식
   속도도 일반 함수보다 함수 객체가 더 빠르다.
   함수 객체는 인라인될 수 있고, 컴파일러가 쉽게 최적화할 수 있다.
*/


// 멤버 변수를 갖는 함수 객체
class Adder
{
	int total;
public:
	explicit Adder(int n = 0) : total(n){}
	int operator()(int n) // 함수 객체
	{
		return total += n;
	}
};

int main()
{
	Adder add(0); // 초깃값 0
	
	cout << add(10) << endl;
	cout << add(20) << endl;
	cout << add(30) << endl;
	cout << add(30.3) << endl;
	return 0;
}