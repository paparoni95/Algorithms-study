#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "";
	int pos = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();
	answer = "김서방은 " + to_string(pos) + "에 있다";
	return answer;
}