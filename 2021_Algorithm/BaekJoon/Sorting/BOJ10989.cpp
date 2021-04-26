#include <iostream>
using namespace std;

int n;
int cnt[10001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << i << '\n';
		}
	}
	return 0;
}