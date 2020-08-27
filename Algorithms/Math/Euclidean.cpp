#include <iostream>
using namespace std;

// 유클리드 호제법
// 최대 공약수를 구하는 알고리즘
// 시간 복잡도 O(logN)

// 재귀
int recursive(int a, int b)
{
	if (b == 0) return a;
	else return recursive(b, a % b);
}

// 반복문
int loop(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main()
{
	cout << recursive(12, 8) << endl;
	cout << recursive(8, 12) << endl;
	cout << loop(12, 8) << endl;
	cout << loop(8, 12) << endl;

	cout << recursive(120, 45) << endl;
	cout << recursive(45, 120) << endl;
	cout << loop(120, 45) << endl;
	cout << loop(45, 120) << endl;
	return 0;
}