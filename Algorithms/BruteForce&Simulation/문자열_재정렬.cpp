#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> result;
int num = 0;

int main() {
	cin >> s;
	// 문자를 하나씩 확인하면서
	for (int i = 0; i < s.size(); i++) {
		// 알파벳인 경우 결과 리스트에 삽입
		if (isalpha(s[i])) {
			result.push_back(s[i]);
		}
		// 숫자는 따로 더하기
		else {
			num += s[i] - '0';
		}
	}

	// 알파벳을 오름차순으로 정렬
	sort(result.begin(), result.end());
	// 알파벳을 차례대로 출력
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}
	// 숫자가 하나라도 존재하는 경우 가장 뒤에 출력
	if (num != 0) cout << num;
	return 0;
}