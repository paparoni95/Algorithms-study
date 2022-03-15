#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> pos;

bool valid(int distance)
{
	int cnt = 1; // 0 좌표 집은 공유 설치했다고 가정
	int pivot = 0;
	for (int i = 1; i < pos.size(); i++)
	{
		if (pos[i] - pos[pivot] >= distance)
		{
			pivot = i;
			cnt++;
		}
	}
	return cnt >= C;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> C;
	pos.resize(N);
	for (int i = 0; i < N; i++) cin >> pos[i];

	sort(pos.begin(), pos.end());

	int start = 0;
	int end = pos[N - 1];
	int distance = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (valid(mid))
		{
			distance = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << distance << endl;
	return 0;
}