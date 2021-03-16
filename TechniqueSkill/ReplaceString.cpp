#include <iostream>
#include <string>
#include <algorithm> // replace()
using namespace std;

/*
	# replace
	
	# 함수 원형
	string& replace(size_t index, size_t len, const string& str)
	index 위치에서 len 길이까지의 범위를 매개변수로 들어온 str 전체로 대체한다.
*/

// string::find() 사용
string replaceAll(string& str, const string& from, const string& to)
{
	size_t start = 0; // string 처음부터 검사
	while ((start = str.find(from, start)) != string::npos) // from을 찾을 수 없을 때까지
	{
		// 여기서 start는 from 문자를 발견한 인덱스 위치
		str.replace(start, from.length(), to);
		start += to.length(); // 중복검사를 피하고 from.length() > to.length()인 경우를 위해서
	}
	return str;
}

int main()
{
	// 단어 하나만 바꾸는 경우
	string str1 = "blah#blah";
	replace(str1.begin(), str1.end(), 'a', '?'); // bl?h#bl?h
	cout << str1 << endl;

	// 문자를 바꾸는 경우
	string str2 = "Number Of Beans";
	string str3 = "ghghjghugtghty";
	string str4 = "ghghjghugtghty";
	std::cout << replaceAll(str2, std::string(" "), std::string("_")) << std::endl;
	std::cout << replaceAll(str3, std::string("gh"), std::string("X")) << std::endl;
	std::cout << replaceAll(str4, std::string("gh"), std::string("h")) << std::endl;
}