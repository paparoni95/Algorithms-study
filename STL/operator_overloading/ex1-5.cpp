#include <iostream>
using namespace std;

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	void Print() const { cout << x << ',' << y << endl; }
	void operator+(Point arg)
	{
		/* 연산자 오버로딩의 핵심은 클래스 타입(사용자 정의 타입)의
		객체에 연산자를 사용하면 컴파일러는 정의된 함수를 호출한다.*/
		cout << "operator+() 함수 호출" << endl;
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5);
	p1 + p2; // => p1.operator+(p2); 와 같음
	return 0;
}