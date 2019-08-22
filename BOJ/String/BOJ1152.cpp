#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int length = s.size();
	int word_count = 1; // 단어의 개수

	// 이 로직은 공백을 만나면 그 앞은 단어의 개수로 친다.

	// 시작부터 공백으로 간다면
	if (s[0] == ' ') {
		word_count = 0;
	}
	else {
		word_count = 1;
	}
	for (int i = 0; i < length; i++) {
		// 공백을 기준으로 그 앞은 단어이므로 추가한다.
		// 단, 현재 인덱스가 마지막 인덱스가 아니면
		if (i != length -1 && s[i] == ' ') {
			word_count++;
		}
		else if (i == length - 1 && s[i] == ' ') {

		}
	}
	cout << word_count;
	return 0;
}