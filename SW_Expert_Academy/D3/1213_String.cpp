#include <iostream>
#include <string>
using namespace std;

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int n;
		cin >> n;

		string str1, str2;
		int answer = 0;
		cin >> str1; // 패턴 문자열
		cin >> str2; // 입력 문자열

		int found = 0;
		while ((found = str2.find(str1)) != string::npos)
		{
			answer++;
			str2 = str2.substr(++found);
		}

		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}