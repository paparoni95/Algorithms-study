#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	const Point operator+(const Point& arg)
	{
		/* 연산자 오버로딩은 컴파일러와 약속된 함수를 이용해
		사용자 정의 타입에 연산이 가능하도록 제공하는 것*/
		Point pt;
		pt.x = this->x + arg.x;
		pt.y = this->y + arg.y;
		return pt;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	Point p3;
	
	p3 = p1 + p2;
	p3.Print();
	p3 = p1.operator+(p2); // 직접 호출하는 방법
	p3.Print();
	p3 = p3 + p1;
	p3.Print();
	return 0;
}