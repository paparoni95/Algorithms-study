#include <string>
#include <vector>

using namespace std;

// 전화번호의 뒷 4자리를 제외한 나머지 숫자를 전부 * 로 처리
string solution(string phone_number) {
	int len = phone_number.length();
	for (int i = 0; i < len - 4; ++i)
		phone_number[i] = '*';

	return phone_number;
}