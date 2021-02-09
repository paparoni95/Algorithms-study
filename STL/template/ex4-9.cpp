/* 함수 템플릿 특수화(Function Template Specialization 

   특수화된 버전의 함수 템플릿을 더 제공하는 것   
*/
#include <iostream>
using namespace std;

class Point
{
	int x; int y;
public:
	explicit Point(int _x = 0, int _y = 0) : x(_x),y(_y){}
	void Print() const { cout << x << ',' << y << endl; }
};

// 일반화 함수 템플릿
template<typename T>
void Print(T a)
{
	cout << a << endl;
}

// 특수화 함수 템플릿
template<>
void Print(Point a)
{
	cout << "Print 특수화 버전: ";
	a.Print();
}

int main()
{
	int n = 10;
	double d = 2.5;
	Point pt(2, 3);

	Print(n);  // Print<int>(n) 일반화 버전 호출
	Print(d);  // Print<double>(d) 일반화 버전 호출
	Print(pt); // Print<Point>(pt) 특수화 버전 호출

	return 0;
}