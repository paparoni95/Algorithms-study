#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// backtracking
int l, c;
vector<char> input;

bool isValid(string& s) {
	int chk1 = 0; // a,e,i,o,u
	int chk2 = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') chk1++;
		else chk2++;
	}

	return (chk1 >= 1 && chk2 >= 2);
}

bool vis[15];
void findPassword(int cnt, int idx, string s) {
	if (cnt == l) {
		if (isValid(s)) {
			cout << s << '\n';
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		if (vis[i] == false) {
			vis[i] = true;
			findPassword(cnt + 1, i + 1, s + input[i]);
			vis[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> l >> c;
	input.resize(c);
	for (int i = 0; i < c; i++) cin >> input[i];

	sort(input.begin(), input.end());

	findPassword(0, 0, "");
	
	return 0;
}