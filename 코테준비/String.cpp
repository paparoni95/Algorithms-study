// https://pluslab.tistory.com/73
// string에 대해서 잘 정리된 것 같아서 가져왔다.

#include <iostream>
#include <string>
using namespace std;

void strTest1()
{
	// string의 기본적인 입출력 기능들
	cout << "strTest1()" << endl;

	string str;
	cout << "string 입력: ";
	cin >> str;
	cout << "str : " << str << endl;
}

void strTest2()
{
	cout << "strTest2()" << endl;

	// string 생성 및 초기화

	string str1 = "This is string 1.";
	string str2("This is string 2.");
	string str3(str2);

	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;
	cout << "str3 : " << str3 << endl;
}

void strTest3()
{
	cout << "strTest3()" << endl;

	// string에 문자 또는 문자열 추가
	string str = "Test";
	cout << "str : "<< str << endl;
	str += " Message.";
	cout << "str : " << str << endl;

	str.append(" Appended string."); // 문자열의 뒤에 내용을 추가
	cout << "str : " << str << endl;

	string str2 = str + " new message";
	cout << "str2 : " << str2 << endl;
}

void strTest4()
{
	cout << "strTest4()" << endl;

	// string의 길이 구하기
	string str = "This is Test Message.";
	cout << "str : " << str << endl;
	cout << "str.size() : " << str.size() << endl;
	cout << "str.length() : " << str.length() << endl;

	string str2 = "This";
	cout << "str2 : " << str2 << endl;
	cout << "str2.size() : " << str2.size() << endl;
	cout << "str2.length() : " << str2.length() << endl;
}

void strTest5()
{
	cout << "strTest5()" << endl;

	// char배열(C에서의 string)에서 string 생성하기
	char message[] = "This is a C style string."; // Null 문자가 포함됨

	/* C언어에서는 string이 따로 없기 때문에 char배열로 표현
	   
	   주의할 점은 C언어에서 char배열로 string을 표현할 때는
	   string의 끝 뒤에 \0을 넣어주기 때문에, 그렇지 않은 배열은 string
	   으로의 변환이 제대로 동작하지 않는다.*/
	string str(message);
	cout << "char array : " << message << endl;
	cout << "char array length : " << strlen(message) << endl;
	cout << "string : " << str << endl;
	cout << "string length : " << str.length() << endl;

	// char 배열에서 널문자를 넣어주지 않으면 쓰래기 값이 출력됨.
	char noCstring[] = { 'N', 'O' };
	string str2(noCstring);
	cout << str2 << endl;
}

void strTest6()
{
	cout << "strTest6()" << endl;

	// string의 동적 생성 및 반환
	string* str = new string("동적 생성된 메시지");
	cout << "str address : " << str << endl; // 포인터의 주소가 출력
	cout << "str : " << *str << endl;

	str->append(". 포인터이기 때문에 append는 이렇게 수행");
	cout << "str address : " << str << endl;
	cout << "str : " << *str << endl;
	delete str;
}

void strTest7()
{
	cout << "strTest7()" << endl;

	// string을 한 줄 전체로 입력받기

	/* string을 입력받을 때 띄어쓰기가 있으면 그 앞까지만 입력받는다.*/
	string str1, str2;
	cin >> str1 >> str2;
	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;

	// 버퍼에 '\n'이 남아있게 되므로 입력 버퍼를 초기화 해준다.
	while (getchar() != '\n') {}

	getline(cin, str1, '\n');  // '\n'이 나올 때까지 입력을 받도록 지정
	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;
}

void strTest8()
{
	cout << "strTest8()" << endl;

	// string 중 특정 위치의 문자 가져오기

	/* at()을 사용하면 해당 인덱스에 있는 문자를 char형태로 반환받기 가능
	   이때, 배열처럼 인덱스는 0부터 시작한다.
	   또 at()은 범위를 체크하는 기능도 한다.
	   
	   배열처럼 str[4]로 사용할 수 있지만, 범위 체크는 하지 않는다.
	*/
	string str = "Test Message for index";

	cout << "str : " << str << endl;
	cout << "str.at(0) : " << str.at(0) << endl;
	cout << "str.at(str.length()-1) : " << str.at(str.length() - 1) << endl;

	char c = str.at(1);
	cout << "str.at(1) : " << c << endl;

	for (int i = 0; i < str.length(); i++) cout << str.at(i);
	cout << endl;
}

void strTest9()
{
	cout << "strTest9()" << endl;

	// string간 문자열 비교
	string str1 = "abcd";
	string str2 = "abde";
	string str3 = "abcd";

	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;
	cout << "str3 : " << str3 << endl << endl;

	/* compare를 사용하면 문자열을 비교할 수 있다. 
	   int형을 반환하면서
	   
	   -1을 반환하면 사전적으로 더 앞에 있다.
	    0을 반환하면 동일한 문자열이다.
		1을 반환하면 사전적으로 더 뒤에 있다.
    */
	int cmp = str1.compare(str2);
	cout << "str1과 str2 비교 : " << cmp << endl;

	cmp = str2.compare(str1);
	cout << "str2와 str1 비교 : " << cmp << endl;

	cmp = str1.compare(str3);
	cout << "str1과 str3 비교 : " << cmp << endl;

	cmp = str1.compare(str2);
	if (cmp == 0) cout << "동일한 문자열" << endl;
	else if (cmp < 0) cout << str1 << "이 " << str2 << "보다 사전적으로 앞" << endl;
	else cout << str1 << "이 " << str2 << "보다 사전적으로 뒤" << endl;

	if (str1 == str3) cout << "동일한 문자열" << endl;
	else cout << "다른 문자열" << endl;

	if (str1 == str2)cout << "동일한 문자열" << endl;
	else cout << "다른 문자열" << endl;
}

void strTest10()
{
	cout << "strTest10()" << endl;

	// string 복사
	string str1 = "string 1.";
	/* =를 통해 str을 복사할 수 있다.
	   이때 포인터값만 복사되는 것이 아니라, 값도 복사되고
	   새로운 객체가 만들어진다.
	*/
	string str2 = str1;
	str1 += " appended";
	cout << "str1 : " << str1 << endl;
	cout << "str2 : " << str2 << endl;
}

void strTest11()
{
	cout << "strTest11()" << endl;

	// string 중간에 문자열 추가 및 검색
	string str = "Test for strTest11";
	cout << "str : " << str << endl;

	/* find를 통해 string에 해당 문자열이 있는지 확인할 수 있다.
	   만약 해당 문자열이 없는 경우 string::npos를 반환한다.
	   문자열이 있는 경우는 해당 문자열이 시작하는 인덱스를 반환
	   
	   find의 인자로 찾을 문자열만 주는 경우 문자열의 시작부터 검색
	   두번째 인자로 검색을 시작할 인덱스 값을 지정할 수도 있다.
	*/
	int pos;
	if ((pos = str.find("for")) != string::npos)
	{
		cout << "str.find(\"for\") : " << pos << endl;
		str.insert(pos, "message ");
	}

	cout << "str : " << str << endl;

	str = "abc here def here g here hijkl here";
	cout << "str : " << str << endl;
	pos = 0;
	while ((pos = str.find("here", pos + 1)) != string::npos)
	{
		cout << "pos : " << pos << endl;
	}
}

void strTest12()
{
	cout << "strTest12 : substring" << endl;

	string str = "Test message for strTest12.";
	int pos;

	cout << "str : " << str << endl;
	if ((pos = str.find("message")) != string::npos)
	{
		string str2 = str.substr(pos, str.length() - pos);
		cout << "str2 : " << str2 << endl;
	}
}

int main()
{
	//strTest1();
	//strTest2();
	//strTest3();
	//strTest4();
	//strTest5();
	//strTest6();
	//strTest7();
	//strTest8();
	//strTest9();
	//strTest10();
	//strTest11();
	return 0;
}