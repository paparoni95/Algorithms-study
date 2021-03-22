#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

bool binarySearch(int left, int right,int target)
{
	if (left > right) return false;
	int mid = (left + right) / 2;
	if (v[mid] == target) return true;
	else if (v[mid] > target) return binarySearch(left, mid - 1, target);
	else return binarySearch(mid + 1, right, target);
}

int main()
{
	cin >> N;
	v.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cin >> M; 
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		if (binarySearch(0, N - 1, x))
			cout << "yes ";
		else
			cout << "no ";
	}

	return 0;
}