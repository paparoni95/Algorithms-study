// https://blog.junu.dev/30

// queue를 굳이 한 개를 사용해서 풀려고하지말고, 여러 개를 이용하는 것도 생각해보자.
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	queue<int> q[21];
	vector<string> v;

	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		v.push_back(str);
	}

	long ans = 0;
	for(int i = 0; i < n; i++)
	{
		string now = v[i];
		int idx = now.length();

		if (q[idx].empty())
			q[idx].push(i);
		else
		{
			// 좋은 친구 조건을 만족하지 못하면, 퇴출
			while (i - q[idx].front() > k)
			{
				q[idx].pop();
				if (q[idx].empty()) break;
			}
				

			ans += q[idx].size();
			q[idx].push(i);
		}
	}

	cout << ans;
	return 0;
}