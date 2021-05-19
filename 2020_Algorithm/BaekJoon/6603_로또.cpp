#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;
void solve(vector<int>& v, int index, int cnt)
{
	if (cnt == 6)
	{
		for (int elem : lotto)
		{
			cout << elem << ' ';
		}
		cout << '\n';
		return;
	}

	if (index >= v.size()) return;

	lotto.push_back(v[index]);
	solve(v, index + 1, cnt + 1);
	lotto.pop_back();
	solve(v, index + 1, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	while (1)
	{
		int k;
		cin >> k;

		if (k == 0) break;

		vector<int> v(k, 0);
		for (int i = 0; i < k; i++) cin >> v[i];

		solve(v, 0, 0);
		cout << '\n';
	}
	return 0;
}