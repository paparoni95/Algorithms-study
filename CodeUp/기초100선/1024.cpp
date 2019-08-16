#include <stdio.h>

int main()
{
	char str[21];
	scanf("%s", str);
	int idx = 0;
	while (str[idx] != NULL) {
		printf("\'%c\'\n", str[idx]);
		idx++;
	}
	return 0;
}