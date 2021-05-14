#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
	string str = "java+=c+=c+++=python";
	int previous = 0;
	int current = 0;
	vector<string> v;

	current = str.find("+="); // 4
	while (current != string::npos)
	{
		string substring = str.substr(previous, current - previous);
		v.push_back(substring);
		previous = current + 2; // 구분자가 "+="의 길이만큼 더해준다.
		current = str.find("+=", previous);
	}
	v.push_back(str.substr(previous, current - previous));
	for (string s : v) cout << s << endl;
	return 0;
}