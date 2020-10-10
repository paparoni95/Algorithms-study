#include <iostream>
#include <utility>
using namespace std;

// pair
// 2개의 데이터를 저장할 수 있는 변수이다.
// 비교 연산시 1순위 first, 2순위 second로 판별한다.

int main()
{
	// int, int 자료형을 저장하는 변수 선언
	pair<int, int> p;
	// (4,5)를 삽입
	p = make_pair(4, 5);
	cout << p.first << ' ' << p.second << '\n';
	// c++11부터 가능
	p = { 5, 6 };
	// 출력
	cout << p.first << ' ' << p.second << '\n';
	return 0;
}