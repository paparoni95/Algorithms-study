#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& v, int n)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = 0; k < v.size(); k++)
			{
				// 3개의 삼각수의 합으로 표현되는 자연수이면
				if (n == v[i] + v[j] + v[k])
				{
					return true;
				}
			}
		}
	}

	return false;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int k;
	cin >> k;
	// 삼각수를 미리 구해 놓는다.
	vector<int> v;
	for (int i = 1; i <= 50; i++)
	{
		int t = (i * (i + 1)) / 2;
		v.push_back(t);
	}

	while (k--)
	{
		int n;
		cin >> n;
		if (solve(v, n)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
	return 0;
}