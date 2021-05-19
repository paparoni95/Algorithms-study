#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int cnt = 0;
	long long n = num;

	while (n != 1)
	{
		++cnt;

		if (n % 2 == 0)
			n /= 2;
		else
		{
			n *= 3;
			++n;
		}

		if (cnt == 501)
		{
			cnt = -1;
			break;
		}
	}


	return cnt;
}