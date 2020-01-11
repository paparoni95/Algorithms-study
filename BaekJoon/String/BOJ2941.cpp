#include <iostream>
#include <string>
using namespace std;

// c인 경우 뒤에 =, -
// d인 경우 뒤에 -, 만약에 z이면 뒤에 = 확인
// l인 경우 뒤에 j,
// n인 경우 뒤에 j,
// s인 경우 뒤에 =,
// z인 경우 뒤에 =,

int main() {
	string s;
	cin >> s;
	int length = s.length();
	int alpha_count = 0;

	for (int i = 0; i < length; i++) {
		if (i + 1 < length && s[i] == 'c' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'c' && s[i + 1] == '-') {
			alpha_count++;
			i++;
			continue;
		}
		else if (s[i] == 'd') {
			if (i + 1 < length && s[i + 1] == '-') {
				alpha_count++;
				i++;
				continue;
			}
			else if (i + 2 < length && s[i + 1] == 'z' && s[i + 2] == '=') {
				alpha_count++;
				i += 2;
				continue;
			}
			else {
				alpha_count++;
				continue;
			}
		}
		else if (i + 1 < length && s[i] == 'l' && s[i + 1] == 'j') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'n' && s[i + 1] == 'j') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 's' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else if (i + 1 < length && s[i] == 'z' && s[i + 1] == '=') {
			alpha_count++;
			i++;
			continue;
		}
		else
			alpha_count++;
	}
	
	cout << alpha_count;
	return 0;
}