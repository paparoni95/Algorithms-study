#include<iostream>
#include<string>
using namespace std;

bool check(string& str)
{
	for (int i = 0; i < str.size(); ++i)
		if (str[i] == '3' || str[i] == '6' || str[i] == '9')
			return false;

	return true;
}

void count369(string& str)
{
	int count = 0;
	for (int i = 0; i < str.size(); ++i)
		if (str[i] == '3' || str[i] == '6' || str[i] == '9')
			count++;

	for (int i = 0; i < count; ++i)
		cout << "-";
	cout << " ";
}

int main(int argc, char** argv)
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		string s = to_string(i);
		if (check(s))
			cout << i << " ";
		else
			count369(s);
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}