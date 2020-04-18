#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	while (1)
	{
		int N;
		cin >> N;
		if (N == 0) break;

		vector<int> v(N + 1, 0);
		stack<int> st;
		for (int i = 0; i < N; i++)
			cin >> v[i];

		long long ans = 0;
		for (int i = 0; i < N + 1; i++)
		{
			while (!st.empty() && v[st.top()] >= v[i])
			{
				long long height = v[st.top()];
				st.pop();

				long long width = 0;
				if (st.empty()) width = i;
				else width = i - st.top() - 1;

				ans = max(ans, height * width);
			}

			st.push(i);
		}

		cout << ans << '\n';
	}
	return 0;
}