#include <stdio.h>

int main()
{
	// 간단한 포인터 사용법
	int a = 5;
	int *b = &a;
	printf("%d\n", a);
	printf("%d\n", *b);

	// 배열 각 원소의 주소 값 출력
	int c[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", &c[i]);
	}

	// 더블 포인터 사용법
	int d = 10;
	int *e = &d;
	int **f = &e;
	printf("%d\n", d);
	printf("%d\n", *e);
	printf("%d\n", **f);

	// 포인터와 배열의 관계
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int *arrPtr = arr; // 배열의 이름 자체가 배열의 시작 주소값이다.
	printf("%d\n", arr[2]);
	printf("%d\n", arrPtr[2]);
	return 0;
}