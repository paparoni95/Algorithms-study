#include <iostream>
#include <cstring>
using namespace std;

class String
{
	//char buf[100];
	char* str;
public:
	String(const char* sz)
	{
		str = new char[strlen(sz) + 1];

		int i = 0;
		for (i = 0; sz[i] != '\0'; i++)
			str[i] = sz[i];
		str[i] = '\0'; // 항상 마지막은 널문자로 넣어주기.
	}
	operator const char* () const
	{
		return str;
	}

	~String()
	{
		delete[] str;
	}
};

int main()
{
	String s("Hello!");
	const char* sz = s;
	cout << sz << endl;
	return 0;
}