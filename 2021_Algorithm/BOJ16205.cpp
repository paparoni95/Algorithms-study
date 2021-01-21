#include <iostream>
#include <string>
#include <vector>
#include <cctype> // isupper, islower, toupper, tolower 함수 사용
using namespace std;

int n;
string input;

string makeCamelCase(string str)
{
	if (str.size() == 0) return "";

	string result;
	result += tolower(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == '_')
		{
			result += toupper(str[i + 1]);
			i++;
		}
		else
			result += str[i];
	}

	return result;
}

string makeSnakeCase(string str)
{
	if (str.size() == 0) return "";

	string result;

	result += tolower(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (isupper(str[i]))
		{
			result += '_';
			result += tolower(str[i]);
		}
		else
			result += str[i];
	}

	return result;
}

string makePascalCase(string str)
{
	if (str.size() == 0) return "";

	string result;
	result += toupper(str[0]);
	for (int i = 1; i < str.size(); i++)
	{
		if (str[i] == '_')
		{
			result += toupper(str[i + 1]);
			i++;
		}
		else
			result += str[i];
	}

	return result;
}

int main()
{
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> input;

	cout << makeCamelCase(input) << '\n';
	cout << makeSnakeCase(input) << '\n';
	cout << makePascalCase(input) << '\n';

	return 0;
}