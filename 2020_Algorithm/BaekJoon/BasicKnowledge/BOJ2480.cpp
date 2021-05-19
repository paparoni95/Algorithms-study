#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> num(3, 0);
	for (int i = 0; i < 3; ++i) cin >> num[i];
	if (num[0] == num[1] && num[0] == num[1] && num[1] == num[2]) cout << 10000 + num[0] * 1000;
	else if (num[0] == num[1]) cout << 1000 + num[0] * 100;
	else if (num[0] == num[2]) cout << 1000 + num[0] * 100;
	else if (num[1] == num[2]) cout << 1000 + num[1] * 100;
	else {
		int max_dice = *max_element(num.begin(), num.end());
		cout << max_dice * 100;
	}
	return 0;
}