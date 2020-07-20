#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool flag = true; // 단어의 시작은 대문자로 시작한다.
	                  // 대문자 -> 소문자 -> 대문자...

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == ' ')
		{
			answer += ' ';
			flag = true;
		}

		else
		{
			if (flag)
			{
				flag = false;
				answer += toupper(s[i]); // 대문자로 바꿔주기
			}

			else
			{
				flag = true;
				answer += tolower(s[i]); // 소문자로 바꿔주기
			}
		}
	}
	return answer;
}