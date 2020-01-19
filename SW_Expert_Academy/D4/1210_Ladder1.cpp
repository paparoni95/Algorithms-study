#include <iostream>
#include <cstring>
using namespace std;

int a[101][101];
int finish_y;
int answer = 0;


int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int cycle;
		cin >> cycle;

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> a[i][j];
				// 도착지점의 좌표 기록.
				if (a[i][j] == 2)
				{
					finish_y = j;
				}
			}
		}

		// 도착지점에서부터 출발해서 출발 지점을 찾는다.
		for (int i = 99; i >= 0; i--)
		{
			// 중요한 점은 올라오면서, 왼쪽이나 오른쪽 지점이 있으면 그곳으로 이동한다.
			// 우선 왼쪽에 길이 있다면
			if (a[i][finish_y - 1] == 1)
			{
				while (true)
				{
					finish_y--; // 왼쪽으로 이동하고
					if (a[i][finish_y - 1] == 0) // 다시 확인
						break;
				}
			}
			// 오른쪽에 길이 있다면
			else if (a[i][finish_y + 1] == 1)
			{
				while (true)
				{
					finish_y++; // 오른쪽으로 이동하고
					if (a[i][finish_y + 1] == 0)
						break;
				}
			}
		}

		cout << "#" << test_case << " " << finish_y << endl;
	}
	return 0;
}