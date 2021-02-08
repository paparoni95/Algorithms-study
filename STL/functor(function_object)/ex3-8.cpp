#include <iostream>
#include <functional> // plus<>, minus<> 헤더
using namespace std;

// plus, minus 함수 객체 구현

struct Plus
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};

struct Minus
{
	int operator()(int a, int b)
	{
		return a - b;
	}
};

int main()
{
	cout << Plus()(10, 20) << endl;
	cout << Plus()(20, 10) << endl;
	cout << Minus()(10, 20) << endl;
	cout << Minus()(20, 10) << endl;
	cout << endl;

	cout << plus<int>()(10, 20) << endl;
	cout << plus<int>()(20, 10) << endl;
	cout << minus<int>()(10, 20) << endl;
	cout << minus<int>()(20, 10) << endl;

	return 0;
}