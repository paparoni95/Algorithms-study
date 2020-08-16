#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 출처: https://velog.io/@pa324/프로그래머스-Level-1-문자열-압축카카오-2020공채-문제
// 문자열의 길이가 1000이므로,
// 충분히 완전탐색으로 풀 수 있었지만,
// 구현력 부분에서 어려웠다..

int solution(string s) {
	int len = s.size();
	int answer = len;

	for (int i = 1; i <= (len / 2); ++i) {
		string result = "";
		string word = s.substr(0, i);
		int count = 1;

		for (int j = i; j <= len; j += i) {
			if (word == s.substr(j, i)) {
				++count;
			}
			else { // 문자열이 다르면
				if (count == 1) {
					result += word;
				}
				else {
					result += (to_string(count) + word);
				}

				word = s.substr(j, i);
				count = 1;
			}
		}
		// 끝 문자열이 추가가 되었는지 확인
		if (len / i != 0) {
			result += s.substr((len / i) * i);
		}
		if (answer > result.size())
			answer = result.size();
	}

	return answer;
}