#include <iostream>
#include <vector>
using namespace std;

int T, N, cycle;

bool candySameCheck(const vector<int>& v)
{
	if (v.size() == 1) return true;

	for (int i = 1; i < v.size(); i++)
	{
		if (v[0] != v[i]) return false;
	}

	return true;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--)
	{
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}

		cycle = 0;
		while (1)
		{
			for (int i = 0; i < N; i++)
			{
				if (v[i] % 2 != 0) v[i]++;
			}

			if (candySameCheck(v))
			{
				cout << cycle << '\n';
				break;
			}
			
			vector<int> v2(N, 0);
			for (int i = 0; i < N; i++)
			{
				v2[i] = v[i] / 2;
				v[i] = v2[i];
			}

			for (int i = 1; i < N; i++)
				v[i] += v2[i - 1];
			v[0] += v2[v2.size() - 1];

			cycle++;
		}
	}

	return 0;
}
