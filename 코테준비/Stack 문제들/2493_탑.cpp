#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> v(n + 1, 0);
	vector<int> ans(n + 1, 0);
	stack<int> st;

	for (int i = 1; i <= n; i++)
		cin >> v[i];

	for (int i = n; i >= 1; i--)
	{
		while (!st.empty() && v[st.top()] < v[i])
		{
			ans[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';

	return 0;
}