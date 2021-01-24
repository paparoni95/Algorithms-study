#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int prize(const vector<int>& dice)
{
	vector<int> tmp;

	for (int i = 1; i <= 6; i++)
	{
		if (dice[i] > 0)
			tmp.push_back(i);

		if (dice[i] == 4)
			return 50000 + i * 5000;
		else if (dice[i] == 3)
			return 10000 + i * 1000;
		else if (dice[i] == 2)
		{
			for (int j = i + 1; j <= 6; j++)
			{
				if (dice[j] == 2)
				{
					return 2000 + i * 500 + j * 500;
				}
			}

			return 1000 + i * 100;
		}
	}

	return (*max_element(tmp.begin(), tmp.end())) * 100;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, answer = 0;
	cin >> N;
	while (N--)
	{
		int num;
		vector<int> dice(7, 0);
		for (int i = 0; i < 4; i++)
		{
			cin >> num;
			dice[num]++;
		}

		answer = max(answer, prize(dice));
	}

	cout << answer;

	return 0;
}