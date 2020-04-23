#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	// 애초에 카드가 1장이면 정답은 1
	if (n == 1)
	{
		cout << 1;
		return 0;
	}

	int kard = 0;
	while (1)
	{
		// 제일 위에 있는 카드를 뺀다. (카드가 한 장 남으면 끝)
		if (!q.empty()) q.pop();
		if (q.size() == 1) break;
		// 제일 위에 있는 카드를 가장 마지막에 넣는다.
		kard = q.front();
		q.pop();
		q.push(kard);
	}

	cout << q.front();
	return 0;
}