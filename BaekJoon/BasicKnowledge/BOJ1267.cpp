#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> time(n, 0);
	for (int i = 0; i < n; ++i) cin >> time[i];

	int yungmin_money = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = time[i] / 30;
		yungmin_money += 10 + cnt * 10;
	}

	int dongho_money = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = time[i] / 60;
		dongho_money += 15 + cnt * 15;
	}

	if (yungmin_money == dongho_money) {
		cout << "Y M " << yungmin_money << '\n';
	}
	else if (yungmin_money > dongho_money) {
		cout << "M " << dongho_money << '\n';
	}
	else {
		cout << "Y " << yungmin_money << '\n';
	}
	return 0;
}