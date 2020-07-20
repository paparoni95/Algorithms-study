#include <string>
#include <vector>

using namespace std;

int solution(int n) {

	if (n == 0) return 0;
	if (n == 1) return 1;

	vector<int> v;

	v.push_back(1);
	v.push_back(n);
	for (int i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			v.push_back(i);

			if (n / i != i)
				v.push_back(n / i);
		}
	}

	int answer = 0;
	for (int i = 0; i < v.size(); ++i)
		answer += v[i];

	return answer;
}