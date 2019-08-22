#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string s;
	cin >> s;

	int alpha[26];
	memset(alpha, 0, sizeof(alpha));

	int length = s.size();
	for (int i = 0; i < length; i++) {
		// 문자가 소문자라면
		if (s[i] >= 'a' && s[i] <= 'z') {
			alpha[s[i] - 'a']++;
		} // 문자가 대문자라면
		else if (s[i] >= 'A' && s[i] <= 'Z') {
			alpha[s[i] - 'A']++;
		}
	}

	int max_value = 0;
	char ans_alpha;
	// 저장된 알파벳의 개수 중에서 최댓값을 찾는다.
	for (int i = 0; i < 26; i++) {
		if (max_value < alpha[i]) {
			max_value = alpha[i];
			ans_alpha = (char)(i + 'A');
		}
			
	}

	// 가장 많이 사용된 알파벳의 숫자와 동일한 부분이 있는지 체크
	int check = 0;
	for (int i = 0; i < 26; i++) {
		if (max_value == alpha[i])
			check++;
	}

	// 동일한 부분이 있으므로
	if (check > 1) {
		cout << "?";
	}
	else {
		cout << ans_alpha;
	}
	
	return 0;
}