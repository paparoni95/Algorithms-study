#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";

	char start;
	for (auto c : s)
	{
		if (c >= 'A' && c <= 'Z')
			start = 'A';
		else if (c >= 'a' && c <= 'z')
			start = 'a';

		if (c != ' ')
			c = (c + n - start) % 26 + start;

		answer += c;
	}
	return answer;
}