#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<long long> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stoll(s));
	}

	sort(v.begin(), v.end());
	for (auto ret : v)
		cout << ret << '\n';
	cout << '\n';
	return 0;
}