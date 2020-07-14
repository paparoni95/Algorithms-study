#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	// C스타일에서 2차원 배열로 문자열 받기
	// 항상 문자열의 끝을 의미하는 NULL문자까지 크기를 고려해서 잡아준다.
	char a[8][9];
	for (int i = 0; i < 8; i++)
		scanf("%s", a[i]);
	
	int ans = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && a[i][j] == 'F')
				ans++;
		}
	}

	printf("%d", ans);
	return 0;
}