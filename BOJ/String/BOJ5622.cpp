#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 2 - ABC
// 3 - DEF
// 4 - GHI
// 5 - JKL
// 6 - MNO
// 7 - PQRS
// 8 - TUV
// 9 - WXYZ

vector<pair<string, int>> v;


void Setting() {
	v.push_back(make_pair("ABC", 2));
	v.push_back(make_pair("DEF", 3));
	v.push_back(make_pair("GHI", 4));
	v.push_back(make_pair("JKL", 5));
	v.push_back(make_pair("MNO", 6));
	v.push_back(make_pair("PQRS",7));
	v.push_back(make_pair("TUV", 8));
	v.push_back(make_pair("WXYZ",9));
}

bool Matching(char ch, int index) {
	int length = 3; // 보통 길이가 3이지만
	// 전화번호 버튼 7번과 9번은 길이가 4이다.
	if (v[index].second == 7 || v[index].second == 9) {
		length = 4;
	}
	for (int i = 0; i < length; i++) {
		if (ch == v[index].first[i])
			return true;
	}
	return false;
}

int main() {
	Setting();
	string phone_number_string;
	
	cin >> phone_number_string;

	int phone_number_length = phone_number_string.length();
	int phone_book_length = v.size();
	int time_count = 0;

	for (int i = 0; i < phone_number_length; i++) { // 들어온 단어를 하나씩 본다.
		for (int j = 0; j < phone_book_length; j++) { // 기억하고 있는 전화번호부에서
			if (Matching(phone_number_string[i], j)) { // 단어랑 현재 비교하는 항목이랑 같으면 시간을 더해준다.
				time_count += v[j].second;
				break;
			}
		}
	}

	time_count += phone_number_length;
	cout << time_count;

	return 0;
}