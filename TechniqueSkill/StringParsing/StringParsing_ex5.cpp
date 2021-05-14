/*
	문자열을 나누는 stringstream
	주어진 문자열에서 필요한 자료형에 맞는 정보를 꺼낼 때 유용

	공백과 '\n'을 제외하고 문자열에서 맞는 자료형의 정보를 꺼냄.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	string str = "123 456 789";
	stringstream ss(str); // 현재 stream 값을 문자열 str로 갱신
	while (ss >> n) cout << n << endl;
	cout << endl;

	vector<int> time;
	string query = "2021:05:15 12:59:31";
	for (int i = 0; i < query.size(); i++)
	{
		if (query[i] == ':') query[i] = ' ';
	}

	stringstream ss2(query);
	//while (ss2 >> n) time.push_back(n);
	//for (auto p : time) cout << p << endl;
	//cout << endl;

	string str2;
	vector<string> time2;
	while (ss2 >> str2) time2.push_back(str2);
	for (auto p : time2) cout << p << endl;
	cout << endl;
	return 0;
}