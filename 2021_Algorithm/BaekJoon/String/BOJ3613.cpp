#include <iostream>
#include <string>
using namespace std;

// 첫 번째 문자로 '_'나 대문자
// '_'가 연속으로 나오는 경우
// '_' 다음에 대문자
// c++ 라고 인식했는대 대문자가 나오면
// java 라고 인식했는대  '_' 가 나오는 경우
// 마지막 문자가 '_'인 경우

int main()
{
	string s;
	cin >> s;

	bool cpp = false, java = false, err = false;
	string ret;
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			if (i == 0 || cpp)
			{
				err = true;
				break;
			}
			ret += '_';
			ret += tolower(s[i]);
			java = true;
		}
		else if (s[i] == '_')
		{
			if (!i || java || i == s.length() - 1 ||
				s[i + 1] == '_' || isupper(s[i + 1]))
			{
				err = true;
				break;
			}
			ret += toupper(s[i + 1]);
			i++;
			cpp = true;
		}
		else
			ret += s[i];
	}

	if (err)
		cout << "Error!\n";
	else
		cout << ret << '\n';

	return 0;
}