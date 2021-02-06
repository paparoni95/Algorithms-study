#include <iostream>
using namespace std;

/* 단항 연산자 오버로딩 */

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }

	const Point& operator++() // 전위 ++
	{
		++x;
		++y;
		return *this; // this는 주소이므로 *붙여서 자기 자신을 리턴
	}

	const Point operator++(int) // 후위 ++
	{
		Point pt(x, y);
		++x;
		++y;
		return pt;
	}
};

int main()
{
	Point p1(2, 3), p2(2, 3);
	Point result;

	result = ++p1; // p1.operator++(); 와 같음
	p1.Print();
	result.Print();

	result = p2++; // p2.operator++(0); 와 같음
	p2.Print();
	result.Print();
	return 0;
}