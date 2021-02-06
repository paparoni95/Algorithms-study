#include <iostream>
using namespace std;

/* 여러 인자를 받는 함수 호출 연산자 */

struct FuncObject
{
public:
	void operator()(int arg) const
	{
		cout << "정수 : " << arg << endl;
	}
	
	void operator()(int arg1, int arg2) const
	{
		cout << "정수 : " << arg1 << ',' << arg2 << endl;
	}

	void operator()(int arg1, int arg2, int arg3) const
	{
		cout << "정수 : " << arg1 << ',' << arg2 << ',' << arg3 << endl;
	}
};

int main()
{
	FuncObject print;
	print(10); // 객체 생성 후 호출(암시적)
	print(10, 20);
	print(10, 20, 30);
	cout << endl;

	print.operator()(10); // 객체 생성 후 호출(명시적)
	print.operator()(10, 20);
	print.operator()(10, 20, 30);
	cout << endl;

	/* 임시 객체는 그 문장에서 생성되고 그 문장을 벗어나면 소멸된다. */
	FuncObject()(10); // 임시 객체로 호출(암시적)
	FuncObject()(10, 20);
	FuncObject()(10, 20, 30);
	cout << endl;

	FuncObject().operator()(10); // 임시 객체로 호출(명시적)
	FuncObject().operator()(10, 20);
	FuncObject().operator()(10, 20, 30);

	return 0;
}