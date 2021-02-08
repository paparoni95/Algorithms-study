#include <iostream>
#include <functional> // less<> 헤더
using namespace std;

// STL less 함수 객체
typedef less<int> Less;

int main()
{
	Less l;

	cout << l(10, 20) << endl; // 객체로 암시적 함수 호출
	cout << l(20, 10) << endl;
	cout << l.operator()(10, 20) << endl; // 객체로 명시적 함수 호출
	cout << endl;

	cout << Less()(10, 20) << endl; // 임시 객체로 암시적 함수 호출
	cout << Less()(20, 10) << endl;
	cout << Less().operator()(10, 20) << endl; // 임시 객체로 명시적 함수 호출
	cout << less<int>()(10, 20) << endl;

	return 0;
}