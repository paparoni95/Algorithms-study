#include <iostream>
using namespace std;

int n, target;
int arr[101];

int main()
{
	freopen("input.txt", "r", stdin);

	cin >> n;
	for (int i = 0; i < n; ++i) cin >> arr[i];
	cin >> target;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (target == arr[i])
			cnt++;
	}

	cout << cnt << '\n';
	return 0;
}