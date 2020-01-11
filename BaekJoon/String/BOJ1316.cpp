#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 그룹 단어란 각 문자가 연속해서 나타나는 경우를 말한다.
// ccazzzzbb는 c,a,z,b가 모두 연속해서 나타나므로 그룹 단어이다.
// aabbbccb는 b가 떨어져서 나타나므로 그룹 단어가 아니다.

// a ~ z까지 배열을 만들어서 하나라도 등장했으면 체크, 아니라면 false
// 단어를 하나씩 검사하면서 등장했는데 또 등장하면 그 단어는 그룹 단어가 아니다.


int main() {
	int n;
	int ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
	
		bool alpha[26]; // 알파벳 체크 배열
		bool ok = true;
		bool continue_check = true;
		memset(alpha, false, sizeof(alpha));
		cin >> s;

		int length = s.length();
		// 첫 단어는 확인해주고
		char first_char = s[0];
		alpha[s[0] - 'a'] = true;

		// 다음 단어부터 본다.
		for (int j = 1; j < length; j++) {
			// 이전과 다른 알파벳이 나오면
			if (s[j - 1] != s[j]) {
				// 처음 마킹하는 알파벳인지 확인
				if (!alpha[s[j] - 'a'])
					alpha[s[j] - 'a'] = true;
				else {
					ok = false;
					break;
				}
			}
		}

		if (ok)
			ans++;
	}

	cout << ans;
	return 0;
}