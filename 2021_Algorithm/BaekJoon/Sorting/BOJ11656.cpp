#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
string s;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;
	v.reserve(s.length());
	for (int i = 0; i < s.length(); i++)
	{
		v.push_back(s.substr(i));
	}

	sort(v.begin(), v.end());

	for (auto ret : v)
		cout << ret << '\n';
	cout << '\n';
	return 0;
}