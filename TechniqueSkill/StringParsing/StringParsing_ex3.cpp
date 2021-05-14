#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// 구분자가 2개 이상일 때 유용
// find + substr
int main()
{
	string str = "java,c,c++,python";
	int previous = 0;
	int current = 0;
	vector<string> x;

	current = str.find(','); // 4
	//find 못찾으면 npos 리턴
	while (current != string::npos)
	{
		string substring = str.substr(previous, current - previous);
		x.push_back(substring);
		previous = current + 1;
		current = str.find(',', previous);
	}
	x.push_back(str.substr(previous, current - previous));

	for (string s : x) cout << s << endl;
	return 0;
}