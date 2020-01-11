#include <iostream>
#include <vector>
using namespace std;

int ans;

void solve(vector<int>& v, int index, int sum, int goal)
{
	// 정답의 경우
	if (sum == goal && index == v.size())
	{
		ans++;
		return;
	}
	// 불가능한 경우
	if (index >= v.size())
		return;
	// 다음 경우
	solve(v, index + 1, sum + v[index], goal);
	solve(v, index + 1, sum, goal);
}

int main()
{
	int n, s;
	cin >> n >> s;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	solve(v, 0, 0, s);

	if (s == 0) // 합이 0이라면, 공집합은 제외해야 한다.
		cout << ans - 1;
	else
		cout << ans;

	return 0;
}