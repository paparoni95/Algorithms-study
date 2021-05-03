#include <string>
#include <vector>
using namespace std;
// 가운데 글자 가져오기(구현)
string solution(string s) {
	if (s.size() % 2 == 0) {
		return s.substr(s.size() / 2 - 1, 2);
	}
	else {
		return s.substr(s.size() / 2, 1);
	}
}