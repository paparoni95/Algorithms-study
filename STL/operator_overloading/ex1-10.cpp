#include <iostream>
using namespace std;

/* ==, != 연산자 오버로딩*/

class Point
{
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }
	bool operator==(const Point& arg) const
	{
		return x == arg.x && y == arg.y ? true : false;
	}
	bool operator!=(const Point& arg) const
	{
		// != 연산자는 == 연산자의 부정이므로
		return !(*this == arg);
	}
};

int main()
{
	Point p1(2, 3), p2(5, 5), p3(2, 3);

	if (p1 == p2)
		cout << "p1 == p2" << endl;
	if (p1 == p3)
		cout << "p1 == p3" << endl;
	if (p1 != p2)
		cout << "p1 != p2" << endl;
	if (p1 != p3)
		cout << "p1 != p3" << endl;

	return 0;
}