#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	// scanf함수는 EOF을 만나게 되면, -1을 리턴하게 된다.
	// 성공이라면, 성공한 인자들의 수를 리턴한다.
	while (scanf("%d %d", &a, &b) != EOF)
	{
		printf("%d\n", a + b);
	}
	return 0;
}