#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int k;

	while (1)
	{
		cin >> k;

		if (k == 0)
			break;

		vector<int> num(k);
		for (int i = 0; i < k; i++)
			cin >> num[i];

		vector<int> lotto(k);
		for (int i = 0; i < 6; i++)
			lotto[i] = 1;
		for (int i = 6; i < k; i++)
			lotto[i] = 0;

		sort(lotto.begin(), lotto.end());

		vector<vector<int>> ans;

		do
		{
			vector<int> temp;
			for (int i = 0; i < k; i++)
			{
				if (lotto[i])
					temp.push_back(num[i]);
			}

			ans.push_back(temp);
		} while (next_permutation(lotto.begin(), lotto.end()));
		

		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
		{
			for (int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j] << ' ';

			cout << '\n';
		}

		cout << '\n';
	}
	return 0;
}