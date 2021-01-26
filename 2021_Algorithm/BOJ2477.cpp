#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 문제 접근법
// 비어 있는 사각형의 넓이를 찾는다.
// 찾는 방법은 한 변의 길이를 기준으로 그 전의 길이와 앞의 길이의 합이
// 전체 사각형의 너비 또는 높이일 경우 우리가 찾는 빈 사각형의 너비 또는 높이일 것이다.

int k;
int w, h;
int ww, hh;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> k;
	vector<int> v(6);
	for (int i = 0; i < 6; i++)
	{
		int tmp;
		cin >> tmp >> v[i];
		if (i % 2 == 0)
			h = max(h, v[i]);
		else
			w = max(w, v[i]);
	}

	// 한 변을 기준으로 보면,
	// 뒤의 변과 앞의 변의 합이 전체 사각형의 너비 또는 높이일 경우
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
		{
			if (w == v[(i + 5) % 6] + v[(i + 1) % 6])
				hh = v[i];
		}
		else
		{
			if (h == v[(i + 5) % 6] + v[(i + 1) % 6])
				ww = v[i];
		}
	}
	cout << (w * h - ww * hh) * k;
	return 0;
}