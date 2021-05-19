#include <iostream>

#define MAX 1000000
using namespace std;

int calc(int num)
{
	int sum = num;
	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int main()
{
	int n;
	cin >> n;

	bool find = false;
	for (int i = 1; i <= MAX; i++)
	{
		//cout << i << "의 분해합은 " << calc(i) << endl;
		if (n == calc(i))
		{
			//cout << "정답은 " << i << "입니다." << endl;
			cout << i << '\n';
			find = true;
			break;
		}
	}

	// 정답을 찾지 못했다면
	if (!find)
	{
		cout << 0 << '\n';
	}
	return 0;
}