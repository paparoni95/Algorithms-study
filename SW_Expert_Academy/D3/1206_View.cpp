#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int end = 0;
		int answer = 0;
		cin >> end;
		vector<int> v(end);

		//  현재 빌딩들의 높이 저장
		for (int i = 0; i < end; i++)
		{
			cin >> v[i];
		}

		vector<int> buildings(5);
		for (int start = 2; start < end - 2; start++)
		{
			// 자신의 빌딩의 위치(start)를 기준으로 왼쪽 -1, -2 오른쪽 +1, +2를 살펴본다.
			// 자신을 포함한 5개 중에서 가장 큰 것과 그 다음으로 큰 것을 찾는다.
			buildings[0] = v[start - 2];
			buildings[1] = v[start - 1];
			buildings[2] = v[start];
			buildings[3] = v[start + 1];
			buildings[4] = v[start + 2];

			sort(buildings.begin(), buildings.end());

			// 가장 큰 빌딩의 높이가 현재 자신의 빌딩이 아니라면 패스
			if (v[start] != buildings[4])
				continue;
			else // 정답에 추가
				answer += buildings[4] - buildings[3];
		}

		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}