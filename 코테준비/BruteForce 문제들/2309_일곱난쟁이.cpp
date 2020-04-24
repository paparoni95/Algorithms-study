#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	vector<int> v(9, 0);
	int total = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> v[i];
		total += v[i];
	}
		
	bool find = false;
	int idx1, idx2;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (i != j)
			{
				if (total - v[i] - v[j] == 100)
				{
					find = true;
					idx1 = i;
					idx2 = j;
					break;
				}
			}
		}

		if (find) break;
	}

	vector<int> ans;
	for (int i = 0; i < 9; i++)
	{
		if (v[i] != v[idx1] && v[i] != v[idx2])
			ans.push_back(v[i]);
	}

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
	return 0;
}