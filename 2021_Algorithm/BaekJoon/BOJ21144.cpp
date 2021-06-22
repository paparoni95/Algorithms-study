#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	int make = 1;
	while (s.size()) {
		if (make <= 9) {
			if (make == s[0] - '0') {
				s = s.substr(1);
				make++;
			}
			else
				break;
		}
		else if (make <= 99) {
			if (make == stoi(s.substr(0, 2))) {
				s = s.substr(2);
				make++;
			}
			else
				break;
		}
		else if (make >= 100) {
			if (make == stoi(s.substr(0, 3))) {
				s = s.substr(3);
				make++;
			}
			else
				break;
		}
		
	}

	cout << make << '\n';
	return 0;
}