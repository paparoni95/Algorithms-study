#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> priorities, int location)
{
	queue<int> printer;
	vector<int> sorted;
	for (int i = 0; i < priorities.size(); ++i)
		printer.push(i);

	while (!printer.empty())
	{
		int now_index = printer.front();
		printer.pop();
		if (priorities[now_index] != *max_element(priorities.begin(), priorities.end()))
		{
			printer.push(now_index);
		}
		else
		{
			sorted.push_back(now_index);
			priorities[now_index] = 0;
		}
	}

	for (int i = 0; i < sorted.size(); ++i)
	{
		if (sorted[i] == location) 
			return i + 1;
	}
}