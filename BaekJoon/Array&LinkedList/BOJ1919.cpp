#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	string str1, str2;
	cin >> str1 >> str2;
	vector<int> a(26, 0);
	vector<int> b(26, 0);
	for (auto c : str1) a[c - 'a']++;
	for (auto c : str2) b[c - 'a']++;
	for (int i = 0; i < a.size(); ++i) a[i] -= b[i];

	int answer = 0;
	for (int i = 0; i < a.size(); ++i)
		answer += abs(a[i]);

	cout << answer;
	return 0;
}