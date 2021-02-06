#include <iostream>
using namespace std;

/* 전역 함수를 이용한 연산자 오버로딩 */

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	int GetX() const { return x; }
	int GetY() const { return y; }

	friend const Point operator-(const Point& argL, const Point& argR);
};

/* 전역 함수를 이용하면 private 멤버인 x와 y에 접근할 수 없으므로
getter를 이용하거나 friend 함수를 이용한다. */
//const Point operator-(const Point& argL, const Point& argR)
//{
//	return Point(argL.GetX() - argR.GetX(), argL.GetY() - argR.GetY());
//}

/* 프렌드 함수는 캡슐화를 저해하므로 가능하면 게터, 세터를 사용하는 방법이 좋다. */
const Point operator-(const Point& argL, const Point& argR)
{
	return Point(argL.x - argR.x, argL.y - argR.y);
}


int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;

	p3 = p1 - p2;
	p3.Print();

	return 0;
}