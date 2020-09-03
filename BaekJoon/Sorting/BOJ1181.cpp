#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//길이가 짧은 것부터
//길이가 같으면 사전 순으로
struct Compare {
	bool operator()(string a, string b) {
		if (a.length() < b.length())
			return true;
		else if (a.length() == b.length() && a < b)
			return true;
		else
			return false;
	}
};
int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	sort(v.begin(), v.end(), Compare());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";

	return 0;
}