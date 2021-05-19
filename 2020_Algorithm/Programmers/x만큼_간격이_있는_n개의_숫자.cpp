#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
	vector<long long> answer;

	answer.push_back(x);
	long long sum = x;
	for (int i = 0; i < n - 1; ++i)
	{
		sum += x;
		answer.push_back(sum);
	}

	return answer;
}