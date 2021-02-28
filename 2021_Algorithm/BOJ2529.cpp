#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 순열을 만들고 거기서 조건에 맞는 값만 추출하여 구한다.

int k;
char sign[10];
bool check[10];

vector<string> ans;
vector<char> v;

bool compare(int idx, char c)
{
	if (c == '<')
	{
		if (v[idx] - '0' < v[idx + 1] - '0') return true;
		return false;
	}
	else if (c == '>')
	{
		if (v[idx] - '0' > v[idx + 1] - '0') return true;
		return false;
	}
}

bool isValid()
{
	for (int i = 0; i < k; i++)
	{
		if (!compare(i, sign[i]))
			return false;
	}
	return true;
}

void dfs(int cnt)
{
	if (cnt == k + 1)
	{
		if (isValid())
		{
			string s;
			for (int i = 0; i < v.size(); i++) s += v[i];
			ans.push_back(s);
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(i + '0');
			dfs(cnt + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("input.txt", "r", stdin);

	cin >> k;
	for (int i = 0; i < k; i++) cin >> sign[i];

	dfs(0);
	sort(ans.begin(), ans.end());
	cout << ans.at(ans.size() - 1) << endl;
	cout << ans.at(0) << endl;
	return 0;
}