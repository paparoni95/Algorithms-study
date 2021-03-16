#include <iostream>
#include <string>
using namespace std;

/*
	# std::string::find 함수 원형
	size_t find(const string& str, size_t pos = 0) const noexcept;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_type n) const;
	size_t find(char c, size_t pos = 0) const noexcept;

	#parameter
	str : 검색 문자열
	pos : 검색에서 고려할 문자열의 첫 번째 문자 위치
	s : 문자 배열에 대한 포인터
	n : 일치시킬 문자 시퀀스의 길이
	c : 검색 문자

*/

string replaceAll(string& str, const string& from, const string& to)
{
	size_t start = 0;
	while ((start = str.find(from, start)) != string::npos)
	{
		str.replace(start, from.length(), to);
		start += to.length();
	}
	return str;
}

int main()
{
	string str = "There are two needles in this haystack with needles.";
	string str2 = "needles";

	// size_t : 부호없는 정수 유형
	size_t found = str.find(str2);
	if (found != string::npos)
	{
		cout << "first 'needle' found ad: " << found << '\n';
	}

	// 3번째 인덱스는 일치시킬 문자 시퀀스의 길이
	found = str.find("needles are small", found + 1, 7);
	if (found != string::npos)
	{
		cout << "second 'needles' found at: " << found << '\n';
	}

	found = str.find("haystack");
	if (found != string::npos)
	{
		cout << "'haystack' also found at: " << found << '\n';
	}

	found = str.find('.');
	if (found != string::npos)
	{
		cout << "Period found at: " << found << '\n';
	}

	string str3 = str;
	str3.replace(str3.find(str2), str2.length(), "preposition");
	cout << str3 << '\n';

	string str4 = str;
	str4 = replaceAll(str4, str2, "preposition");
	cout << str4 << '\n';
	return 0;
}