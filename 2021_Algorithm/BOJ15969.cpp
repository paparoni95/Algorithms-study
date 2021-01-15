#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	int maxPoint = 0, minPoint = 0;
	maxPoint = *max_element(v.begin(), v.end());
	minPoint = *min_element(v.begin(), v.end());

	cout << maxPoint - minPoint << '\n';
	return 0;
}