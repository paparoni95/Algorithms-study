#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string s) {

	int consonant = 0; // 자음의 개수
	int vowel = 0;     // 모음의 개수

	// 최소 한 개의 모음과 최소 두 개의 자음으로 구성되어 있다.
	int length = s.length();

	for (int i = 0; i < length; i++) {
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
			vowel++;
		}
		else
			consonant++;
	}

	if (vowel >= 1 && consonant >= 2)
		return true;
	else
		return false;
}

void make_password(int n, vector<char>& v, string password, int i) {
	// 정답을 찾은 경우
	if (n == password.length()) {
		if (check(password)) {
			cout << password << '\n';
			return;
		}
	}
	// 불가능한 경우
	if (i >= v.size()) return;
	// 다음 경우
	make_password(n, v, password + v[i], i + 1); // 현재 알파벳을 사용
	make_password(n, v, password, i + 1);        // 현재 알파벳을 사용하지 않는다.
}

int main() {
	int L, C;
	cin >> L >> C;
	vector<char> password;
	for (int i = 0; i < C; i++) {
		char ch;
		cin >> ch;
		password.push_back(ch);
	}

	sort(password.begin(), password.end());
	make_password(L, password, "", 0);
	return 0;
}