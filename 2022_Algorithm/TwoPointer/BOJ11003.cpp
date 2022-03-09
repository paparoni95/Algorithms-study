#include <iostream>
#include <deque>
using namespace std;

int N, L;
int arr[5000001];

// 구간의 합이 L로 고정되어 있을 때는 슬라이딩 윈도우 기법을 이용한다.
// 다만 이 문제는 그 구간에서 최소값을 리턴해야 되기 때문에
// 들어오는 원소의 값이 기존에 있는 원소값보다 크다면?
// 앞에 제거하고 들어온다.

// => 창문 방법을 이용하면서 안의 구조를 유지하는 방법이 추가된 문제
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++) cin >> arr[i];

	deque<pair<int, int> > dq;
	for (int i = 0; i < N; i++)
	{
		// 현재 탐색 구간이 아닌 원소들은 빼기
		if (!dq.empty() && dq.front().second + L == i)
		{
			dq.pop_front();
		}

		// 오름차순을 보장하기 위해서 들어오는 원소보다 큰 원소가 자리잡고 있다면, 빼주기
		while (!dq.empty() && dq.back().first > arr[i])
		{
			dq.pop_back();
		}

		dq.push_back({ arr[i], i });
		cout << dq.front().first << ' ';
	}

	return 0;
}