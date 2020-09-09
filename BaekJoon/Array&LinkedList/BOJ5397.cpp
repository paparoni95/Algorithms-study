#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;

		// insert, erase를 하면 iterator의 위치가 달라진다.
		list<char> password;
		auto cursor = password.end();
		for (auto c : str) {
			if (c == '<') {
				if (cursor != password.begin())
					cursor--;
			}
			else if (c == '>') {
				if (cursor != password.end())
					cursor++;
			}
			else if (c == '-') {
				if (cursor != password.begin()) {
					cursor--;
					// erase는 다음 원소를 가리킨다.
					cursor = password.erase(cursor);
				}
			}
			else {
				// insert는 삽입 위치를 그대로 가지고
				password.insert(cursor, c);
			}
		}
		for (auto c : password) cout << c;
		cout << '\n';
	}
	return 0;
}