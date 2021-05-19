#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	int index = 0;
	for (auto elem : seoul)
	{
		if (elem == "Kim")
			break;

		++index;
	}

	return "김서방은 " + to_string(index) + "에 있다";
}