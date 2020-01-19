#include <iostream>
#include <vector>
using namespace std;

int FindMaxHeight(vector<int>& vec)
{
	int max_height = 0, idx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (max_height <= vec[i])
		{
			max_height = vec[i];
			idx = i;
		}
	}

	return idx;
}

int FindMinHeight(vector<int>& vec)
{
	int min_height = 101, idx = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (min_height >= vec[i])
		{
			min_height = vec[i];
			idx = i;
		}
	}

	return idx;
}

// 평탄화를 더 진행해야 되는지
bool Check(vector<int>& vec)
{
	int max_height = vec[FindMaxHeight(vec)];
	int min_height = vec[FindMinHeight(vec)];
	if ((max_height - min_height) >= 2)
		return true;

	return false;
}

int main()
{
	for (int test_case = 1; test_case <= 10; test_case++)
	{
		int dump;
		int max_height_idx = 0, min_height_idx = 0;
		cin >> dump;

		vector<int> heights(100);
		// 모든 상자의 높이들을 담는다.
		for (int i = 0; i < 100; i++)
			cin >> heights[i];

		for (int i = 0; i < dump; i++)
		{
			// 먼저 평탄화 작업을 계속해야 되는지 체크한 후,
			if (!Check(heights))
				break;

			// 평탄화 작업이 필요하면 아래와 같이 작업을 수행한다.
			// 가장 높은 상자의 높이와 가장 낮은 상자의 높이의 인덱스를 찾아서
			// 가장 높은 상자의 높이는 1 감소, 가장 낮은 상자의 높이는 1 증가
			max_height_idx = FindMaxHeight(heights);
			min_height_idx = FindMinHeight(heights);
			heights[max_height_idx]--;
			heights[min_height_idx]++;
		}

		// 가장 높은 높이 - 가장 낮은 높이 = 구하는 답
		int answer = 0;
		max_height_idx = FindMaxHeight(heights);
		min_height_idx = FindMinHeight(heights);
		answer = heights[max_height_idx] - heights[min_height_idx];

		cout << "#" << test_case << " " << answer << endl;

	}
}