#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 4

// next_permutation : 0(N)
// prev_permutation : O(N)
// all_permutation : O(N * N!)

int main()
{
	vector<int> v(MAX);
	for (int i = 0; i < MAX; i++)
		v[i] = i + 1;

	cout << "처음 순열은? " << endl;
	for (int i = 0; i < MAX; i++)
		cout << v[i] << ' ';
	cout << endl;

	cout << "다음 순열은? " << endl;
	if (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < MAX; i++)
			cout << v[i] << ' ';

		cout << endl;
	}

	cout << "이전 순열은? " << endl;
	if (prev_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < MAX; i++)
			cout << v[i] << ' ';

		cout << endl;
	}

	cout << "모든 순열은? " << endl;
	sort(v.begin(), v.end());
	do
	{
		for (int i = 0; i < MAX; i++)
			cout << v[i] << ' ';

		cout << endl;
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}