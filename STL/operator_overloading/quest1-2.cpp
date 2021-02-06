#include <iostream>
#include <cstring>
using namespace std;

class String
{
	char* buf;
public:
	String(const char* sz)
	{
		buf = new char[strlen(sz) + 1];
	}
	~String()
	{
		delete[] buf;
	}
	const String& operator=(const String& arg) // 깊은 복사
	{
		delete[] buf;
		buf = new char[strlen(arg.buf) + 1];
		strcpy(buf, arg.buf);
		return *this;
	}
};

int main()
{
	const char* sz = "Hello!";
	String s("Hi~!");
	s = sz; // s = String(sz); 로 암묵적인 생성자를 이용한 타입 변환
	return 0;
}