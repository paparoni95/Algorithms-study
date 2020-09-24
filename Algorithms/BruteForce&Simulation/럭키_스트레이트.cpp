#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.size() / 2; i++) sum += s[i] - '0';
	for (int i = s.size() / 2; i < s.size(); i++) sum -= s[i] - '0';
	if (sum == 0) cout << "LUCKY\n";
	else cout << "READY\n";
	return 0;
}