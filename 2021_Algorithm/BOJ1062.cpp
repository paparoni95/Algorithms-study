#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//bruteforce
int n, k, ans;
bool alpha[26];
vector<string> words;

void calc() {
	int cnt = 0;
	for (int tc = 0; tc < words.size(); tc++) {
		string word = words[tc];
		bool ok = true;

		for (int i = 0; i < word.size(); i++) {
			if (alpha[word[i] - 'a'] == false) {
				ok = false;
				break;
			}
		}

		if (ok) cnt++;
	}
	ans = max(ans, cnt);
}

void dfs(int cnt, int idx) {
	if (cnt == k - 5) {
		calc();
		return;
	}

	for (int i = idx; i < 26; i++) {
		if (alpha[i] == false) {
			alpha[i] = true;
			dfs(cnt + 1, i);
			alpha[i] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		words.push_back(str);
	}

	if (k < 5) {
		cout << "0\n";
		return 0;
	}

	// a,c,i,n,t
	alpha['a' - 'a'] = true;
	alpha['c' - 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['n' - 'a'] = true;
	alpha['t' - 'a'] = true;

	dfs(0, 0);

	cout << ans << '\n';
	return 0;
}