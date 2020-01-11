#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main() {
	string s;
	cin >> s;

	int alpha[26];
	memset(alpha, -1, sizeof(alpha));

	int length = s.size();
	int mark = 0;
	for (int i = 0; i < length; i++) {
		// 처음 저장이라면 마크해준다.
		if (alpha[s[i] - 'a'] == -1) {
			alpha[s[i] - 'a'] = mark;
		}
		mark++;
	}

	// 출력
	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << ' ';
	}

	return 0;
}