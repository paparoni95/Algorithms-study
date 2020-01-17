#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int cycle, temp;
		int arr[101] = { 0, };
		int max_value = 0;
		int max_score = 0;

		cin >> cycle;
		for (int i = 0; i < 1000; i++)
		{
			cin >> temp;
			arr[temp]++;
		}

		for (int score = 0; score < 101; score++)
		{
			if (arr[score] >= max_value)
			{
				max_score = score;
				max_value = arr[score];
			}
		}
		cout << "#" << test_case << " " << max_score << endl;
	}
}