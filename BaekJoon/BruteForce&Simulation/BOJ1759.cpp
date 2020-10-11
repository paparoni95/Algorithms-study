#include <bits/stdc++.h>
using namespace std;

int l, c;

bool checkingPassword(const string& password) {
	int a = 0, b = 0; // 자음, 모음

	for (int i = 0; i < password.size(); i++) {
		if (password[i] == 'a' || password[i] == 'e' || password[i] == 'i'
			|| password[i] == 'o' || password[i] == 'u') b++;
		else a++;
	}

	if (b >= 1 && a >= 2) return true;
	else return false;
}

void solve(vector<char>& arr, int index, string password) {
	if (password.size() == l) {
		if (checkingPassword(password)) {
			for (auto s : password) cout << s;
			cout << '\n';
			return;
		}
	}

	if (index >= arr.size()) return;

	solve(arr, index + 1, password + arr[index]);
	solve(arr, index + 1, password);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c;
	vector<char> arr;
	for (int i = 0; i < c; i++) {
		char ch;
		cin >> ch;
		arr.push_back(ch);
	}

	sort(arr.begin(), arr.end());
	solve(arr, 0, "");
	return 0;
}