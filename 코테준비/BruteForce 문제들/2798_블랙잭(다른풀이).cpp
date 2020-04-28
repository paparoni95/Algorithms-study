#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> card(N);
	for (int i = 0; i < N; i++) cin >> card[i];

	int ans = 0, sum = 0;
	for (int i = 0; i < N; i++)
		for(int j = i+1; j< N; j++)
			for (int k = j + 1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= M) ans = max(ans, sum);
			}

	cout << ans;
	return 0;
}