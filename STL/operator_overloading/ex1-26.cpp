#include <iostream>
using namespace std;

/* 타입 변환 연산자 오버로딩을 사용하면
   자신의 타입을 다른 타입으로 변환할 수 있다.*/

class A
{

};

class B
{
public:
	operator A()
	{
		cout << "operator A() 호출" << endl;
		return A();
	}
	operator int()
	{
		cout << "operator int() 호출" << endl;
		return 10;
	}

	operator double()
	{
		cout << "operator double() 호출" << endl;
		return 5.5;
	}
};

int main()
{
	A a;
	int n;
	double d;

	B b;
	a = b; // b.operator A() 암시적 호출
	n = b; // b.operator int() 암시적 호출
	d = b; // b.operator double() 암시적 호출
	cout << endl;

	a = b.operator A(); // 명시적 호출
	n = b.operator int();
	d = b.operator double();
	return 0;
}