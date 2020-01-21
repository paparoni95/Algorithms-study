#include <iostream>
#include <string>
using namespace std;

// 해당 스트링이 회문인지 판별해주는 함수
bool IsPalindrome(string& s)
{
	if (s.length() == 1)
		return true;
	else
	{
		for (int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--)
		{
			if (s[i] != s[j])
				return false;
		}
	}

	return true;
}

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int length; // 찾아야 하는 회문의 길이
		int answer = 0;
		char a[8][8];

		cin >> length;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> a[i][j];

		// 회문을 찾는 방법은 2가지다.
		// 1. 행 단위로 찾아보기
		
		for (int i = 0; i < 8; i++) // row
		{
			for (int j = 0; j <= 8 - length; j++) // col (start지점)
			{
				string str;
				for (int k = 0; k < length; k++) // 회문의 길이 만큼 스트링에 추가시켜주고
				{
					str += a[i][j + k];
				}
				
				if (IsPalindrome(str))
				{
					//cout << "행 단위 : " << str << endl;
					answer++;
				}
				
			}
		}
		
		
		// 2. 열 단위로 찾아보기
		for (int i = 0; i < 8; i++) // col
		{
			for (int j = 0; j <= 8 - length; j++) // row
			{
				string str;
				for (int k = 0; k < length; k++)
				{
					str += a[j + k][i];
				}
				

				if (IsPalindrome(str))
				{
					//cout << "열 단위 : " << str << endl;
					answer++;
				}
				
			}
		}
		
		cout << "#" << test_case << " " << answer << endl;
	}

	return 0;
}