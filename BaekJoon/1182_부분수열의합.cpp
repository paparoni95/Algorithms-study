#include <iostream>
#include <vector>
using namespace std;

// 각 원소를 포함시킬지 말지를 다 시도해본다.

int ans;

void solve(vector<int>& v, int idx, int sum, int s)
{
	// 정답인 경우
	if (sum == s && idx == v.size())
	{
		ans++;
		return;
	}

	// 불가능한 경우
	if (idx >= v.size()) return;

	// idx에서 숫자를 선택하는 경우
	solve(v, idx + 1, sum + v[idx], s);
	// idx에서 숫자를 선택하지 않는 경우
	solve(v, idx + 1, sum, s);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, s;
	cin >> n >> s;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	solve(v, 0, 0, s);

	if (s == 0) cout << ans - 1;
	else cout << ans;
	return 0;
}