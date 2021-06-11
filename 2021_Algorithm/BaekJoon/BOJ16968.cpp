#include <iostream>
#include <string>
using namespace std;

string s;
int ans;

//같은 숫자가 2번 연속해서 불가능
void dfs(int idx, char ch) {
	if (idx == s.size()) {
		ans++;
		return;
	}

	if (s[idx] == 'd') {
		for (char i = '0'; i <= '9'; i++) {
			if (i != ch) dfs(idx + 1, i);
		}
	}
	else {
		for (char i = 'a'; i <= 'z'; i++) {
			if (i != ch) dfs(idx + 1, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	dfs(0, ' ');
	cout << ans << '\n';
	return 0;
}