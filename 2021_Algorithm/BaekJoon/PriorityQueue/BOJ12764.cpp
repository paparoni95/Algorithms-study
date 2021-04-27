#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int, int> pii;

int n;
pii input[100000 + 1];
set<int> computer;
int ret[100000 + 1];

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;

	sort(input, input + n);

	// 시간 복잡도
	// 10만 x log(10만) <= 1억 연산 충분
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		// 새로운 사람이 앉으려고 할 때
		// 먼저 종료된 사람들을 모두 다 순서에서 빼준다.
		// 이때 우리는 빼준 자리에 들어가 앉을 수 있는 기회가 주워진다.
		while (!pq.empty())
		{
			if (pq.top().first <= input[i].first)
			{
				computer.insert(pq.top().second);
				pq.pop();
			}
			else
				break;
		}

		// 남은 자리가 없으므로 다음 번호의 컴퓨터를 부여한다.
		if (computer.empty())
		{
			pq.push({ input[i].second, cnt });
			ret[cnt]++;
			cnt++;
		}

		// 남은 자리가 있다!
		// 그 자리의 정보를 빼주고 착석한다.
		else
		{
			auto iter = computer.begin();
			pq.push({ input[i].second, *iter });
			ret[*iter]++;
			computer.erase(iter);
		}
	}

	cout << cnt << '\n';
	for (int i = 0; i < cnt; i++)
		cout << ret[i] << ' ';
	cout << '\n';
	return 0;
}