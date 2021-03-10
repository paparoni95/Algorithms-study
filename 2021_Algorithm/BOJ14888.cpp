#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int a[12];
int op1, op2, op3, op4;
int maxN = -1e9, minN = 1e9;

void input()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> op1 >> op2 >> op3 >> op4;
}

void go(int plus, int minus, int mul, int div, int index, int sum)
{
	if (index >= n)
	{
		maxN = max(maxN, sum);
		minN = min(minN, sum);
		return;
	}

	if (plus > 0) go(plus - 1, minus, mul, div, index + 1, sum + a[index]);
	if (minus > 0) go(plus, minus - 1, mul, div, index + 1, sum - a[index]);
	if (mul > 0) go(plus, minus, mul - 1, div, index + 1, sum * a[index]);
	if (div > 0) go(plus, minus, mul, div - 1, index + 1, sum / a[index]);
}

void solve()
{
	input();
	go(op1, op2, op3, op4, 1, a[0]);
	cout << maxN << '\n';
	cout << minN << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}