#include <iostream>
using namespace std;

/* 생성자를 이용한 형변환을 의도하지 않는다면
   생성자는 명시적 호출만 가능하도록 하는 explicit 키워드를 이용하자. */

class Point
{
	int x;
	int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }
};

int main()
{
	Point pt;
	pt.Print();

	// pt = 10; 암시적 생성자 호출이 불가능하다.
	pt = Point(10); // 명시적 생성자 호출만 가능하다.
	pt.Print();
	return 0;
}