// simulation, implementation
#include <iostream>
#include <vector>
using namespace std;

int N, K;

int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> v(N, 0);
	for (int i = 0; i < N; i++)
		cin >> v[i];


	int cycle = 0, next = 0, answer = -1;
	while (cycle < N)
	{
		cycle++;
		//cout << next << " -> " << v[next] << endl;

		if (v[next] == K)
		{
			answer = cycle;
			break;
		}

		next = v[next];
		
	}

	if (answer == -1) cout << -1;
	else cout << answer;
	return 0;
}