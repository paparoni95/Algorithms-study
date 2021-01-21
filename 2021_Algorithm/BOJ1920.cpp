#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v1, v2;

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int num;
	cin >> N;
	v1.reserve(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v1.push_back(num);
	}

	cin >> M;
	v2.reserve(M);
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());
	for (int i = 0; i < v2.size(); i++)
	{
		cout << binary_search(v1.begin(), v1.end(), v2[i]) << '\n';
	}

	return 0;
}