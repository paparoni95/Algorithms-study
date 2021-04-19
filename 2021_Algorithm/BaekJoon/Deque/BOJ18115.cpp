#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// 입력이 10^6이라 O(N)에 해결해야함.
int n;
vector<int> v;
deque<int> dq;

// 문제에서 An이 항상 1이라 나머지 스킬들을 사용하려고 하면 카드가 2장이상 되야한다.
// 따라서 입력이 2 3 3 2 1로 주어지면
// 우리는 거꾸로 거슬러올라가면서 풀어야 해결할 수 있다.

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	int card = 1;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] == 1)
			dq.push_back(card++);
		else if (v[i] == 2)
		{
			int memo = dq.back();
			dq.pop_back();
			dq.push_back(card++);
			dq.push_back(memo);
		}
		else
			dq.push_front(card++);
	}

	while (!dq.empty())
	{
		cout << dq.back() << ' ';
		dq.pop_back();
	}

	return 0;
}