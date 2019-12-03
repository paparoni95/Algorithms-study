#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> num(n);

	for (int i = 0; i < n; i++)
		cin >> num[i];

	vector<int> operation(4); // +,-,*,/ (수량)
	for (int i = 0; i < 4; i++)
		cin >> operation[i];

	vector<int> order; // 순열에 사용하기 위해 순서지정
	int temp = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < operation[i]; j++)
			order.push_back(temp);

		temp++;
	}

	long long min = 1000000000;
	long long max = -1000000000;

	do
	{
		long long sum = num[0];
		for (int i = 1; i < n; i++)
		{
			switch (order[i - 1])
			{
			case 0:
				sum = sum + num[i];
				break;
			case 1:
				sum = sum - num[i];
				break;
			case 2:
				sum = sum * num[i];
				break;
			case 3:
				sum = sum / num[i];
				break;
			}
		}

		if (sum > max)
			max = sum;
		if (sum < min)
			min = sum;
	} while (next_permutation(order.begin(), order.end()));

	cout << max << '\n' << min;
		
	return 0;
}
