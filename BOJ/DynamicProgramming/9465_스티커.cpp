#include <iostream>
#include <algorithm>
using namespace std;

int a[2][100001]; // 2*N의 크기 스티커의 점수가 들어있는 공간
int d[100001][3]; // d[n][k] : 2*N에서 얻을 수 있는 최대 점수
                  // k = 0 이면 스티커를 뜯지 않은 경우
				  // k = 1 이면 위쪽 스티커를 뜯은 경우
                  // k = 2 이면 아래쪽 스티커를 뜯은 경우
int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		int n;
		cin >> n;

		// initialize
		for (int j = 0; j < 100001; j++)
			for (int k = 0; k < 3; k++)
				d[j][k] = 0;

		// input (2 * N matrix)
		for (int j = 0; j < 2; j++)
			for (int k = 1; k <= n; k++)
				cin >> a[j][k];

		
		for (int j = 1; j <= n; j++)
		{
			// 스티커를 떼어내지 않은 경우
			d[j][0] = max(d[j - 1][0], max(d[j - 1][1], d[j - 1][2]));
			
			// 위쪽 스티커를 떼어낸 경우
			d[j][1] = max(d[j - 1][0], d[j - 1][2]) + a[0][j];
			
			// 아래쪽 스티커를 떼어낸 경우
			d[j][2] = max(d[j - 1][0], d[j - 1][1]) + a[1][j];
		}

		// output
		int ans = max(d[n][0], max(d[n][1], d[n][2]));
		cout << ans << '\n';
	}
	return 0;
}