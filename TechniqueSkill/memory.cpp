/* Heap, stack, static 영역의 메모리 */

// 메모리 공간은 크게 스택(stack), 힙(heap), 데이터(data)영역으로 나뉘어진다.

// 데이터 영역(정적 메모리)
// 전역 변수와 static 변수가 할당되는 영역
// 프로그램의 시작과 동시에 할당되고 프로그램이 종료되어야 메모리에서 소멸됨

// 스택 영역
// 컴파일 타임에 크기 결정
// 함수 호출 시 생성되는 지역 변수와 매개 변수가 저장되는 영역
// 함수 호출이 완료되면 사라짐

// 힙 영역
// 런타임에 크기 결정
// 동적으로 할당된 변수

#include <stdio.h>
#include <stdlib.h>

void foo(int a);

int val = 10;                  // 'val' in data area
char string[] = "Hello World"; // 'string' in data area

int main()
{
	int i = 100; // 'i' in stack area
	foo(i);
	return 0;
}

void foo(int a)
{
	int* ptr = (int*)malloc(sizeof(int) * a); // 'ptr' in heap area
}