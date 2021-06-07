#include <iostream>
#include <string>
using namespace std;

string check[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int ans = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-')) {
			ans++;
			i++;
			continue;
		}
		else if (s[i] == 'd') {
			if (s[i + 1] == '-') {
				ans++;
				i++;
				continue;
			}
			else if (s.substr(i, 3) == "dz=") {
				ans++;
				i += 2;
				continue;
			}
		}
		else if (s[i] == 'l' && s[i + 1] == 'j') {
			ans++;
			i++;
			continue;
		}
		else if (s[i] == 'n' && s[i + 1] == 'j') {
			ans++;
			i++;
			continue;
		}
		else if (s[i] == 's' && s[i + 1] == '=') {
			ans++;
			i++;
			continue;
		}
		else if (s[i] == 'z' && s[i + 1] == '=') {
			ans++;
			i++;
			continue;
		}
		ans++;
	}
	cout << ans << '\n';
	return 0;
}