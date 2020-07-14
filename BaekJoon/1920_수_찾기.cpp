#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> a, b;

int BinarySearch(int s, int e, int target)
{
	int mid = (s + e) / 2;

	if (s > e) return 0;
	if (a[mid] == target) return 1;
	else if (a[mid] < target) return BinarySearch(mid + 1, e, target);
	else return BinarySearch(s, mid - 1, target);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);

	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	cin >> M;
	b.resize(M);
	for (int i = 0; i < M; i++) cin >> b[i];

	sort(a.begin(), a.end());

	for (int i = 0; i < b.size(); i++)
	{
		if (BinarySearch(0, a.size() - 1, b[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
	
	return 0;
}