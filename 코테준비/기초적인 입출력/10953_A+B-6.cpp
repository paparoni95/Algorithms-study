#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int tc;
	// C스타일의 scanf함수는 입력 포맷 설정을 통해서 문자열 규칙 사이에 있는 정수들을 뽑아올 수 있다.
	scanf("%d", &tc);
	while (tc--)
	{
		int a, b;
		scanf("%d,%d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}