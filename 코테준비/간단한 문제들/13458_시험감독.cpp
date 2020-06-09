#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B, C;
vector<int> test_room;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		test_room.push_back(A);
	}

	cin >> B >> C;

	long long ans = 0;
	for (int i = 0; i < test_room.size(); i++)
	{
		test_room[i] -= B;
		ans++;

		if (test_room[i] > 0)
		{
			if (test_room[i] % C == 0) ans += (test_room[i] / C);
			else ans += (test_room[i] / C) + 1;
		}
	}

	cout << ans;

	return 0;
}