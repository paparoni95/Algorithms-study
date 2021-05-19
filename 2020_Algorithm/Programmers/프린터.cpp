#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Note
{
	int priority;
	int order;
};

int findMaxPriority(vector<pair<int, int> >& copy)
{
	int priority = 0;
	for (int i = 0; i < copy.size(); ++i)
	{
		priority = max(priority, copy[i].first);
	}

	return priority;
}

int solution(vector<int> priorities, int location) {
	int answer = 0;

	vector<pair<int, int>> printer;
	for (int i = 0; i < priorities.size(); ++i)
		printer.push_back({ priorities[i], i }); // (우선순위, 순서)

	while (!printer.empty())
	{
		Note current;
		current.priority = printer.front().first;
		current.order = printer.front().second;

		if (printer.size() == 1)
		{
			if (current.order == location)
				return answer == 0 ? 1 : ++answer;
		}

		int maxPriority = findMaxPriority(printer);
		// 출력하지 말고, 다시 뒤로 넣는 형식
		if (current.priority < maxPriority)
		{
			printer.push_back({ current.priority, current.order });
			printer.erase(printer.begin());
		}
		// 출력하고, 해당 순서가 내가 찾는 순서이면 출력
		else 
		{
			++answer;
			printer.erase(printer.begin());
			if (current.order == location)
			{
				return answer;
			}
		}

	}
}
