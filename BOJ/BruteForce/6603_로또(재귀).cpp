#include <iostream>
#include <vector>
using namespace std;

vector<int> lotto;
void makeLotto(vector<int>& v, int index, int count, int goal)
{
	// 정답인 경우
	if (count == goal)
	{
		for (auto x : lotto)
		{
			cout << x << ' ';
		}
		cout << '\n';
		return;
	}

	// 불가능한 경우
	if (index >= v.size())
		return;

	// 다음 경우
	lotto.push_back(v[index]); // 로또 번호를 선택o
	makeLotto(v, index + 1, count + 1, goal);
	lotto.pop_back();          // 로또 번호를 선택x
	makeLotto(v, index + 1, count, goal);
}

int main()
{
	int k, s;
	
	while (1)
	{
		cin >> k;

		if (k == 0)
			break;

		vector<int> num(k);
		for (int i = 0; i < k; i++)
			cin >> num[i];

		makeLotto(num, 0, 0, 6);
		cout << '\n';
		//lotto.clear();
	}

	return 0;
}