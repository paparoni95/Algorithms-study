#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, ans;

void solve(vector<int>& card, int idx, int picked, int sum)
{
	if (picked == 3)
	{
		if (sum <= M) ans = max(ans, sum);
		return;
	}

	if (idx >= card.size()) return;

	// 해당 idx 카드를 선택했다.
	solve(card, idx + 1, picked + 1, sum + card[idx]);
	// 해당 idx 카드를 선택하지 않았다.
	solve(card, idx + 1, picked, sum);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	vector<int> card(N);
	for (int i = 0; i < N; i++) cin >> card[i];
	solve(card, 0, 0, 0);
	cout << ans;
	return 0;
}