#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int a;
	char c;
	printf("하나의 정수 입력 : ");
	scanf("%d", &a);
	printf("%d\n", a);
	int temp;
	// 한 자씩 받아서 파일의 끝이거나 개행 문자를 만나면 입력을 멈추므로 항상 입력 버퍼를 비운다.
	while((temp = getchar()) != EOF && temp != '\n') { }
	printf("하나의 문자 입력 : ");
	scanf("%c", &c);
	printf("%c\n", c);
	while ((temp = getchar()) != EOF && temp != '\n') {}
	char *d = "Hello World";
	printf("%c\n", d[1]);
	printf("%c\n", d[4]);
	printf("%c\n", d[8]);

	printf("문자열 입력 : ");
	char f[100];
	gets(f);
	printf("%s\n", f);


	// 문자열 처리를 위한 다양한 함수들
	char k1[] = "dohyun";
	char k2[] = "dohyun";
	char k3[] = "dohyuf";
	printf("문자열의 길이 : %d\n", strlen(k1)); // 6
	printf("두 배열의 사전 순 비교 : %d\n", strcmp(k1, k2)); // 0
	printf("두 배열의 사전 순 비교 : %d\n", strcmp(k1, k3)); // 1
	strcpy(k3, k1);
	printf("복사된 문자열 : %s\n", k3);
	printf("두 배열의 사전 순 비교 : %d\n", strcmp(k1, k3)); // 0

	char r1[20] = "My name is ";
	char r2[20] = "dohyun";
	printf("문자열의 길이 : %d\n", strlen(r1)); // 11(널문자 빼고)
	printf("문자열의 길이 : %d\n", strlen(r2)); // 6(널문자 빼고)
	strcat(r1, r2);   // r1 + r2
	printf("문자열의 길이 : %d\n", strlen(r1)); // 17

	char r3[20] = "i like that";
	char r4[20] = "that";
	printf("찾은 문자열: %s\n", strstr(r3, r4));
	return 0;
}
