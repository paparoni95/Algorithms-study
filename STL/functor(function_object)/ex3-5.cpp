#include <iostream>
using namespace std;

// less는 < 연산자의 함수 객체
// greater > 연산자의 함수 객체

bool Pred_less(int a, int b)
{
	return a < b;
}

// Less 구현
struct Less
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};

int main()
{
	Less l;

	cout << Pred_less(10, 20) << endl;
	cout << Pred_less(20, 10) << endl;
	cout << endl;

	cout << l(10, 20) << endl; // 객체로 암묵적 함수 호출
	cout << l(20, 10) << endl;

	cout << Less()(10, 20) << endl; // 임시 객체로 암묵적 함수 호출
	cout << Less()(20, 10) << endl;
	cout << endl;

	cout << l.operator()(10, 20) << endl; // 명시적 호출
	cout << l.operator()(20, 10) << endl;

	return 0;
}