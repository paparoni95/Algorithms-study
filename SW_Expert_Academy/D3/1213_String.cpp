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
		cin >> str1; // 찾을 패턴
		cin >> str2; // 주어진 스트링

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
