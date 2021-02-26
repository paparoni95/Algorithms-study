#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int n, ans = INT_MAX;
int board[21][21];

bool check[21];

int calc(vector<int>& v)
{
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			sum += board[v[i]][v[j]];
			sum += board[v[j]][v[i]];
		}
	}
	return sum;
}

void go(int idx, int cnt)
{
	if (cnt == n / 2)
	{
		vector<int> a, b;
		for (int i = 0; i < n; i++)
		{
			if (check[i]) a.push_back(i);
			else b.push_back(i);
		}
		ans = min(ans, abs(calc(a) - calc(b)));
		return;
	}
	for (int i = idx; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			go(i + 1, cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
	
	go(0,0);

	cout << ans << endl;
	return 0;
}