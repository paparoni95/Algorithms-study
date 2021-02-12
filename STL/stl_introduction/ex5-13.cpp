// 함수 어댑터 not2 동작 방식
#include <iostream>
#include <functional> // not2 사용
using namespace std;

int main()
{
	// not2는 조건자 함수 객체를 반대 의미의 조건자 함수 객체로 변경하는 어댑터이며,
	// not2는 이항 조건자에 not1은 단항 조건자에 사용한다.
	cout << less<int>()(10, 20) << endl;
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(less<int>())(10, 20) << endl;
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	less<int> l;
	cout << l(10, 20) << endl;
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(l)(10, 20) << endl;
	cout << not2(l)(20, 20) << endl;
	cout << not2(l)(20, 10) << endl;

	return 0;
}